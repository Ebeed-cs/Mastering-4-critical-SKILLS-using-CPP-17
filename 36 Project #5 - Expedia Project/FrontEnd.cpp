// Implementation for FrontEnd class

#include "FrontEnd.h"
#include <iomanip>

FrontEnd::FrontEnd() {
    loginMenu = { { "Login" }, { "Sign Up" } };
    brawseMenu = {
        { "View Profile" }, { "Make Itinerary" }, {"List my itineraries"}, {"Logout"}
    };
    itineraryMenu = { {"Add Flight"} , {"Add Hotel"} , {"Done"} , {"Cancel"} };
    paymentMenthosMenu = { {"Paypal"} , {"Stripe"} , {"Square"} };
}

int FrontEnd::checkChoice(int max, int min) {
    int input = 0;
    while (!(input >= min && input <= max)) {
        std::cout << "Enter number in range " << min << " - " << max << ": ";
        std::cin >> input;
    }
    return input;
}

void FrontEnd::signup() {
    User* u = new User();
    u->read();
    usersManager.addUsers(u);
    usersManager.setCurrentUser(usersManager.getUsersVector().back());

    std::cout << "\n=== Add Payment Cards ===\n";
    std::cout << "1) Debit card\n";
    std::cout << "2) Credit card\n";
    std::cout << "3) Skip (add cards later)\n";

    ICard* c = nullptr;
    int choice = 0;

    while (true) {
        choice = checkChoice(3);

        if (choice == 3) {
            break;
        }

        if (choice == 1) {
            c = new DebitCard();
            std::cout << "\n--- Adding Debit Card ---\n";
        }
        else if (choice == 2) {
            c = new CreditCard();
            std::cout << "\n--- Adding Credit Card ---\n";
        }

        c->read();
        usersManager.getCurrentUser()->addCard(c);
        delete c;
        c = nullptr;

        std::cout << "\nCard added successfully!\n";
        std::cout << "Add another card?\n";
        std::cout << "1) Debit card\n";
        std::cout << "2) Credit card\n";
        std::cout << "3) No, continue\n";
    }

    std::cout << "\n Signup completed successfully!\n\n";

    delete u;
    u = nullptr;
}

void FrontEnd::AddFlight() {
    Flight flight;
    flight.read();
    usersManager.getCurrentUser()->readPersonalInfo();

    FlightManager flightManager;

    bool notResults = flightManager.printSearchAll(flight.from, flight.date_time_from, flight.to,
        flight.date_time_to,
        usersManager.getCurrentUser()->getAdults(),
        usersManager.getCurrentUser()->getChildren());

    if (notResults) return;

    Flight* clientFlight = nullptr;
    FlightItinerary* service = nullptr;
    clientFlight = flightManager.selectFlight(service, flight.from, flight.date_time_from,
        flight.to, flight.date_time_to,
        usersManager.getCurrentUser()->getAdults(),
        usersManager.getCurrentUser()->getChildren());

    FlightItem* fi = new FlightItem(clientFlight, service,
        &(usersManager.getCurrentUser()->getCustomerInfo()));

    usersManager.getCurrentUser()->addToItinerary(fi);

    delete clientFlight;
    std::cout << "\nFlight added to your itinerary successfully!\n";
}

void FrontEnd::Cancel() {
    std::cout << "\nCanceling itinerary...\n\n";
    usersManager.getCurrentUser()->cancelToItinerary();
    std::cout << "\nItinerary canceled. No changes saved.\n\n";
}

void FrontEnd::AddHotel() {
    RoomBase room;
    room.read();

    int needed_rooms = 0;
    std::cout << "Number of rooms needed: ";
    std::cin >> needed_rooms;

    HotelManager hotelManager;

    bool notResults = hotelManager.printSearchAll(room.country, room.city, room.date_from,
        room.date_to, needed_rooms);

    if (notResults) return;
    RoomBase* clientRoom = nullptr;
    HotelItinerary* service = nullptr;
    clientRoom = hotelManager.selectHotel(service, room.country, room.city,
        room.date_from, room.date_to, needed_rooms);

    HotelItem* hi = new HotelItem(clientRoom,
        &(usersManager.getCurrentUser()->getCustomerInfo()),
        service);

    usersManager.getCurrentUser()->addToItinerary(hi);

    delete clientRoom;
    std::cout << "\nHotel added to your itinerary successfully!\n";
}

void FrontEnd::Done() {
    if (usersManager.getCurrentUser()->getTotalItineraryCost() == 0.0) {
        std::cout << "\n========================================\n";
        std::cout << "     YOUR ITINERARY IS EMPTY!\n";
        std::cout << "========================================\n";
        std::cout << "Looks like you haven't added any flights\n";
        std::cout << "or hotels yet. Please add items to your\n";
        std::cout << "itinerary before proceeding.\n";
        std::cout << "========================================\n\n";
        return;
    }

    std::cout << "\n========================================\n";
    std::cout << "      YOUR ITINERARY SUMMARY\n";
    std::cout << "========================================\n";
    printMenu(usersManager.getCurrentUser()->itemsSummary(), false);
    std::cout << "----------------------------------------\n";
    std::cout << "Total Cost: $" << std::fixed << std::setprecision(2)
        << usersManager.getCurrentUser()->getTotalItineraryCost() << "\n";
    std::cout << "========================================\n\n";

    std::cout << "Do you want to proceed with payment? (y/n): ";

    char answer;
    std::cin >> answer;

    if (answer == 'y' || answer == 'Y') {
        std::cout << "\n========================================\n";
        std::cout << "      SELECT PAYMENT METHOD\n";
        std::cout << "========================================\n";
        printMenu(paymentMenthosMenu);
        int choice = checkChoice(paymentMenthosMenu.size());

        IPayment* paymentMethod = nullptr;
        switch (choice) {
        case 1: paymentMethod = new PayPalPayment(); break;
        case 2: paymentMethod = new StripePayment(); break;
        case 3: paymentMethod = new SquarePayment(); break;
        }

        ICard* selectedCard = nullptr;
        int cardIndex = 0;

        if (usersManager.getCurrentUser()->getCardsVector().size() > 1) {
            std::cout << "\n========================================\n";
            std::cout << "      SELECT PAYMENT CARD\n";
            std::cout << "========================================\n";
            printMenu(usersManager.getCurrentUser()->cardsSummary(), false);
            cardIndex = checkChoice(usersManager.getCurrentUser()->cardsSummary().size()) - 1;
            selectedCard = usersManager.getCurrentUser()->getCardsVector()[cardIndex];
        }
        else {
            selectedCard = usersManager.getCurrentUser()->getCardsVector().back();
        }

        paymentMethod->setCardInfo(selectedCard->getTransactionInfo());

        std::cout << "\n========================================\n";
        std::cout << "      PROCESSING RESERVATIONS...\n";
        std::cout << "========================================\n\n";

        std::vector<ItineraryItem*>& items = usersManager.getCurrentUser()->getItineraryItems();
        std::vector<double> paidAmounts;
        bool allSuccess = true;
        int itemNumber = 1;

        for (auto item : items) {
            double itemCost = item->getCost();

            std::cout << "Processing Item #" << itemNumber++ << " - " << item->getItemType()
                << " ($" << std::fixed << std::setprecision(2) << itemCost << ")...\n";

            if (!selectedCard->hasEnoughBalance(itemCost)) {
                std::cout << "\n----------------------------------------\n";
                std::cout << "       INSUFFICIENT FUNDS!\n";
                std::cout << "----------------------------------------\n";
                std::cout << "Required : $" << std::fixed << std::setprecision(2) << itemCost << "\n";
                std::cout << "Available: $" << std::fixed << std::setprecision(2) << selectedCard->getAvailableBalance() << "\n";
                std::cout << "----------------------------------------\n\n";

                allSuccess = false;
                break;
            }

            bool paymentSuccess = paymentMethod->pay(itemCost, selectedCard);

            if (paymentSuccess) {
                paidAmounts.push_back(itemCost);
                item->reserve();
                std::cout << "----------------------------------------\n";
                std::cout << "Item #" << (itemNumber - 1) << " Reserved Successfully!\n";
                std::cout << "----------------------------------------\n\n";
            }
            else {
                allSuccess = false;
                break;
            }
        }

        if (allSuccess) {
            std::cout << "\n========================================\n";
            std::cout << "   ALL RESERVATIONS CONFIRMED!\n";
            std::cout << "========================================\n";
            std::cout << "Total Amount Paid: $" << std::fixed << std::setprecision(2)
                << usersManager.getCurrentUser()->getTotalItineraryCost() << "\n";
            std::cout << "----------------------------------------\n";
            selectedCard->printCard();
            std::cout << "========================================\n\n";

            usersManager.getCurrentUser()->clearCurrentItinerary();
        }
        else {
            std::cout << "\n========================================\n";
            std::cout << "       ROLLING BACK PAYMENT...\n";
            std::cout << "========================================\n\n";

            double totalRefunded = 0.0;
            for (size_t i = 0; i < paidAmounts.size(); i++) {
                selectedCard->refundAmount(paidAmounts[i]);
                items[i]->cancel();
                totalRefunded += paidAmounts[i];
                std::cout << "Refunded Item #" << (i + 1) << ": $" << std::fixed
                    << std::setprecision(2) << paidAmounts[i] << "\n";
            }

            std::cout << "\n----------------------------------------\n";
            std::cout << "Total Amount Refunded: $" << std::fixed << std::setprecision(2) << totalRefunded << "\n";
            std::cout << "----------------------------------------\n\n";

            std::cout << "========================================\n";
            std::cout << " TRANSACTION FAILED - ALL ITEMS CANCELED\n";
            std::cout << "========================================\n";
            std::cout << "No reservations were made.\n";
            std::cout << "Your card balance has been restored.\n";
            std::cout << "========================================\n\n";

            selectedCard->printCard();
            std::cout << "\n";

            usersManager.getCurrentUser()->cancelToItinerary();
        }

        delete paymentMethod;
    }
    else if (!(answer == 'n' || answer == 'N')) {
        std::cout << "Enter a valid choice\n";
        Done();
    }
}

void FrontEnd::MakeItinerary() {
    int choice = 0;
    while (printMenu(itineraryMenu), (choice = checkChoice(itineraryMenu.size())) != 4)
    {
        switch (choice)
        {
        case 1:
            AddFlight();
            break;
        case 2:
            AddHotel();
            break;
        case 3:
            Done();
            return;
        }
    }
    Cancel();
}

void FrontEnd::ListMyItineraries() {
    usersManager.getCurrentUser()->listMyItineraries();
}

void FrontEnd::login() {
    std::string userName, password;

    std::cout << "Enter username: ";
    std::cin >> userName;

    std::cout << "Enter password: ";
    std::cin >> password;

    User* user = usersManager.searchUsers(userName, password);

    if (user != nullptr) {
        usersManager.setCurrentUser(user);
        std::cout << "\nLogin successful! Welcome " << user->getName() << "\n";
    }
    else {
        std::cout << "\nInvalid credentials. Please try again.\n";
        login();
    }
}

void FrontEnd::printMenu(std::vector<std::string> menu, bool appears) {
    if (appears) std::cout << "Menu:\n";
    for (int i = 0; i < menu.size(); ++i) {
        std::cout << "       " << i + 1 << " : " << menu[i] << "\n";
    }
    std::cout << "\n";
}

void FrontEnd::viewProfile() {
    usersManager.getCurrentUser()->print();
}

void FrontEnd::run() {
    printMenu(loginMenu);
    if (checkChoice(loginMenu.size()) == 1) login();
    else signup();
    std::cout << "Hello " << usersManager.getCurrentUser()->getName() << " | " << "User View" << "\n";
    while (true)
    {
        printMenu(brawseMenu);
        switch (checkChoice(brawseMenu.size())) {
        case 1:
            viewProfile();
            break;
        case 2:
            MakeItinerary();
            break;
        case 3:
            ListMyItineraries();
            break;
        case 4:
            return run();
        }
    }
}

FrontEnd::~FrontEnd() {}

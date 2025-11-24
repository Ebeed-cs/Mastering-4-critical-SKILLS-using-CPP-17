// Implementation for User class

#include "User.h"

User::User() = default;

std::vector<ItineraryItem*>& User::getItineraryItems() {
    return myItineraries;
}

void User::clearCurrentItinerary() {
    for (auto& item : myItineraries) {
        delete item;
    }
    myItineraries.clear();
}

void User::addCard(ICard* card) {
    cards.push_back(card->clone());
}

ICard* User::getCardByIndex(int index) const { // one base -> (index 0 => 1)
    return cards[--index];
}

void User::addToItinerary(ItineraryItem* item) {
    myItineraries.push_back(item->clone());
}

void User::cancelToItinerary() {
    if (myItineraries.empty()) {
        cout << "\nNo itineraries found.\n";
        return;
    }

    for (auto& item : myItineraries) {
        item->cancel();
        delete item;
    }
    myItineraries.clear();
}

void User::reserveToItinerary() {
    for (auto item : myItineraries)
        item->reserve();

    myItineraries.clear();
}

std::string User::getUserName() const {
    return ci.userName;
}

std::string User::getPassword() const {
    return password;
}

std::string User::getName() const {
    return ci.name;
}

std::string User::getEmail() const {
    return ci.email;
}

std::vector<ICard*>& User::getCardsVector() {
    return cards;
}

int User::getAdults() const { return ci.adults; }
int User::getChildren() const { return ci.children; }
int User::getInfants() const { return ci.infants; }

CustomerInfo& User::getCustomerInfo() { return ci; }
const CustomerInfo& User::getCustomerInfo() const { return ci; }

void User::read() {
    std::cout << "\n===== Enter Customer Information =====\n";

    std::cout << "Username       : ";
    std::cin >> ci.userName;

    std::cout << "Password       : ";
    std::cin >> password;

    std::cout << "Full Name      : ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, ci.name);

    std::cout << "Email          : ";
    std::cin >> ci.email;

    std::cout << "=====================================\n\n";
}

void User::readPersonalInfo() {
    std::cout << "Number of Adults   : ";
    std::cin >> ci.adults;

    std::cout << "Number of Children : ";
    std::cin >> ci.children;

    std::cout << "Number of Infants  : ";
    std::cin >> ci.infants;
}

void User::listMyItineraries() const {
    if (myItineraries.empty()) {
        cout << "\nNo itineraries found.\n";
        return;
    }

    cout << "\n========== MY ITINERARIES ==========\n";
    double total = 0.0;

    for (int i = 0; i < (int)myItineraries.size(); i++) {
        cout << "\n--- Item #" << (i + 1) << " ---";
        myItineraries[i]->printItem();
        total += myItineraries[i]->getCost();
    }

    cout << "\n====================================\n";
    cout << "Total Cost: $" << fixed << setprecision(2) << total << "\n";
    cout << "====================================\n";
}

double User::getTotalItineraryCost() const {
    double total = 0.0;
    for (auto item : myItineraries)
        total += item->getCost();
    return total;
}

std::vector<std::string> User::itemsSummary() {
    std::vector<std::string> result;
    for (auto& item : myItineraries)
        result.push_back(item->getItemSummary());
    return result;
}

std::vector<std::string> User::cardsSummary() {
    std::vector<std::string> result;
    for (auto& card : cards)
        result.push_back(card->getCardSummary());
    return result;
}

void User::printUserCards() const {
    if (cards.empty()) {
        std::cout << "Saved Cards    : None\n";
        return;
    }

    std::cout << "Saved Cards    : " << cards.size() << " card(s)\n";
    for (size_t i = 0; i < cards.size(); i++) {
        std::cout << "  Card #" << (i + 1) << ":\n";
        cards[i]->printCard();
    }
}

void User::print(bool personalInfo) const {
    std::cout << "\n===== Customer Information =====\n";
    std::cout << "Username       : " << ci.userName << "\n";
    std::cout << "Full Name      : " << ci.name << "\n";
    std::cout << "Email          : " << ci.email << "\n";

    // Print cards information
    printUserCards();

    if (personalInfo) {
        std::cout << "\n----- Personal Details -----\n";
        std::cout << "Adults   : " << ci.adults << "\n";
        std::cout << "Children : " << ci.children << "\n";
        std::cout << "Infants  : " << ci.infants << "\n";
    }

    std::cout << "================================\n\n";
}

void User::Clear() {
    for (auto& c : cards)
        delete c;
    cards.clear();

    for (auto& i : myItineraries)
        delete i;
    myItineraries.clear();
}

User* User::Clone() {
    return new User(*this);
}

User::User(const User& u) {
    ci = u.ci;
    password = u.password;

    for (auto c : u.cards)
        cards.push_back(c->clone());

    for (auto i : u.myItineraries)
        myItineraries.push_back(i->clone());
}

User& User::operator=(const User& u) {
    if (this == &u)
        return *this;

    ci = u.ci;
    password = u.password;

    Clear();

    for (auto c : u.cards)
        cards.push_back(c->clone());

    for (auto i : u.myItineraries)
        myItineraries.push_back(i->clone());

    return *this;
}

User::~User() {
    Clear();
}

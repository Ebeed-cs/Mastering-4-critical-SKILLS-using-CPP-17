// Header for User class

#ifndef USER_H
#define USER_H

#include <iostream>
#include <iomanip>
#include <vector>
#include "Card.h"
#include "itinerary.h"
#include "FlightAndCustomerInfo.h"
#include "ItineraryItem.h"
#include "FlightItenary.h"
#include <limits>

using namespace std;

class User {
private:
    CustomerInfo ci;
    std::string password;
    std::vector<ICard*> cards;
    std::vector<ItineraryItem*> myItineraries;

public:
    User();
    User(const User& u);
    User& operator=(const User& u);
    ~User();

    std::vector<ItineraryItem*>& getItineraryItems();
    void clearCurrentItinerary();
    void addCard(ICard* card);
    ICard* getCardByIndex(int index) const;
    void addToItinerary(ItineraryItem* item);
    void cancelToItinerary();
    void reserveToItinerary();

    std::string getUserName() const;
    std::string getPassword() const;
    std::string getName() const;
    std::string getEmail() const;

    std::vector<ICard*>& getCardsVector();

    int getAdults() const;
    int getChildren() const;
    int getInfants() const;

    CustomerInfo& getCustomerInfo();
    const CustomerInfo& getCustomerInfo() const;

    void read();
    void readPersonalInfo();
    void listMyItineraries() const;

    double getTotalItineraryCost() const;

    std::vector<std::string> itemsSummary();
    std::vector<std::string> cardsSummary();

    void printUserCards() const;
    void print(bool personalInfo = false) const;

    void Clear();
    User* Clone();
};

#endif

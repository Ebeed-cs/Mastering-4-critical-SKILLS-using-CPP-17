// Header for FrontEnd class

#ifndef FRONTEND_H
#define FRONTEND_H

#include <iostream>
#include "UserManagers.h"
#include "HotelItenary.h"
#include "payment.h"
#include <vector>

class FrontEnd {
private:
    UsersManager usersManager;
    std::vector<std::string> loginMenu;
    std::vector<std::string> brawseMenu;
    std::vector<std::string> itineraryMenu;
    std::vector<std::string> paymentMenthosMenu;

public:
    FrontEnd();

    int checkChoice(int max, int min = 1);
    void signup();
    void AddFlight();
    void Cancel();
    void AddHotel();
    void Done();
    void MakeItinerary();
    void ListMyItineraries();
    void login();
    void printMenu(std::vector<std::string> menu, bool appears = true);
    void viewProfile();
    void run();
    ~FrontEnd();
};

#endif

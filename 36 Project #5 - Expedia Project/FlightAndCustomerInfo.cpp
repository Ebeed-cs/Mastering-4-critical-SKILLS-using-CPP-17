// Implementation for Flight and CustomerInfo classes
#include "FlightAndCustomerInfo.h"

// CustomerInfo implementations
CustomerInfo::CustomerInfo() : adults(0), children(0), infants(0) {}

CustomerInfo::~CustomerInfo() {}

// Flight implementations
Flight::Flight() {
    price = 0.0;
}

void Flight::read() {
    std::cout << "\n===== Enter Flight Information =====\n";
    std::cout << "(Enter actual data or '.' for any)\n\n";

    std::cout << "Departure City : ";
    std::cin >> from;

    std::cout << "Arrival City   : ";
    std::cin >> to;

    std::cout << "Departure Date (DD-MM-YYYY): ";
    std::cin >> date_time_from;

    std::cout << "Arrival Date   (DD-MM-YYYY): ";
    std::cin >> date_time_to;

    std::cout << "====================================\n\n";
}

Flight::~Flight() {}

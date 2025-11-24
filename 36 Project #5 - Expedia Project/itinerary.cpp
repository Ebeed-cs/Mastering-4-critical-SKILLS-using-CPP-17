// Implementation for Itinerary classes

#include "Itinerary.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Iitinerary implementation
void Iitinerary::cancel() {
    std::cout << "Canceled " << getName() << " Reservation \n";
}

// HotelItinerary implementation
void HotelItinerary::reserve() {
    std::cout << "Reserve " << getName() << " successfully \n";
}

// FlightItinerary implementation
std::vector<Flight*> FlightItinerary::search(std::string from, std::string fromDate, std::string to, std::string toDate, int adults, int children) {
    std::vector<Flight*> flights = getFlights(from, fromDate, to, toDate, adults, children);
    Utils::DateParts clientFrom(fromDate);
    Utils::DateParts clientTo(toDate);

    std::vector<Flight*> result;

    for (auto flight : flights) {
        Utils::DateParts flightFrom(flight->date_time_from);
        Utils::DateParts flightTo(flight->date_time_to);

        if (from != "." && flight->from != from) continue;
        if (to != "." && flight->to != to) continue;
        if (fromDate != "." && clientFrom.year != flightFrom.year) continue;
        if (fromDate != "." && clientFrom.month != flightFrom.month) continue;
        if (fromDate != "." && clientFrom.day < flightFrom.day) continue;
        if (toDate != "." && clientTo.year != flightTo.year) continue;
        if (toDate != "." && clientTo.month != flightTo.month) continue;
        if (toDate != "." && clientTo.day > flightTo.day) continue;

        result.push_back(flight);
    }

    return result;
}

void FlightItinerary::print(std::vector<Flight*> flights) {
    cout << "\n=========== " << getName() << " Search Results ===========\n\n";

    if (flights.empty()) {
        cout << "\nNo flights found matching your search criteria.\n";
        return;
    }

    int count = 0;
    for (const auto& f : flights) {
        cout << "Flight #" << ++count << endl;
        cout << "  From            : " << f->from << endl;
        cout << "  To              : " << f->to << endl;
        cout << "  Departure Date  : " << f->date_time_from << endl;
        cout << "  Arrival Date    : " << f->date_time_to << endl;
        cout << "  Price           : $" << fixed << setprecision(2) << f->price << endl;
        cout << "--------------------------------------------------------" << endl;
    }

    cout << "\nTotal Flights Found : " << flights.size() << endl;
    cout << "========================================================\n";
}

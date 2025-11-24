// Implementation for Flight itinerary classes
#include "FlightItenary.h"
#include <iostream>

// ===== AirCanadaCustomerAdapter =====
AirCanadaCustomerAdapter::AirCanadaCustomerAdapter(AirCanadaCustomerInfo& other) {
    userName = other.userName;
    name = other.name;
    email = other.email;
}

AirCanadaCustomerAdapter::AirCanadaCustomerAdapter(CustomerInfo& other) {
    userName = other.userName;
    name = other.name;
    email = other.email;
}

AirCanadaCustomerInfo AirCanadaCustomerAdapter::toApi() {
    AirCanadaCustomerInfo ci;
    ci.userName = userName;
    ci.name = name;
    ci.email = email;
    return ci;
}

// ===== AirCanadaFlightAdapter =====
AirCanadaFlightAdapter::AirCanadaFlightAdapter(AirCanadaFlight& f) {
    price = f.price;
    date_time_from = f.date_time_from;
    date_time_to = f.date_time_to;
    from = f.from;
    to = f.to;
}

AirCanadaFlightAdapter::AirCanadaFlightAdapter(Flight& other) {
    price = other.price;
    date_time_from = other.date_time_from;
    date_time_to = other.date_time_to;
    from = other.from;
    to = other.to;
}

AirCanadaFlight AirCanadaFlightAdapter::toApi() {
    AirCanadaFlight f;
    f.price = price;
    f.date_time_from = date_time_from;
    f.date_time_to = date_time_to;
    f.from = from;
    f.to = to;
    return f;
}

// ===== AirTurkishCustomerAdapter =====
AirTurkishCustomerAdapter::AirTurkishCustomerAdapter(TurkishCustomerInfo& other) {
    userName = other.userName;
    name = other.name;
    email = other.email;
    adults = other.adults;
    children = other.children;
    infants = other.infants;
}

AirTurkishCustomerAdapter::AirTurkishCustomerAdapter(CustomerInfo& other) {
    userName = other.userName;
    name = other.name;
    email = other.email;
}

TurkishCustomerInfo AirTurkishCustomerAdapter::toApi() {
    TurkishCustomerInfo ci;
    ci.userName = userName;
    ci.name = name;
    ci.email = email;
    ci.adults = adults;
    ci.children = children;
    ci.infants = infants;
    return ci;
}

// ===== AirTurkishFlightAdapter =====
AirTurkishFlightAdapter::AirTurkishFlightAdapter(TurkishFlight& f) {
    price = f.cost;
    date_time_from = f.datetime_from;
    date_time_to = f.datetime_to;
    from = f.from;
    to = f.to;
}

AirTurkishFlightAdapter::AirTurkishFlightAdapter(Flight& other) {
    price = other.price;
    date_time_from = other.date_time_from;
    date_time_to = other.date_time_to;
    from = other.from;
    to = other.to;
}

TurkishFlight AirTurkishFlightAdapter::toApi() {
    TurkishFlight f;
    f.cost = price;
    f.datetime_from = date_time_from;
    f.datetime_to = date_time_to;
    f.from = from;
    f.to = to;
    return f;
}

// ===== CanadaFlight =====
std::string CanadaFlight::getName() {
    return "Canada Flight";
}

Iitinerary* CanadaFlight::clone() {
    return new CanadaFlight(*this);
}

std::vector<Flight*> CanadaFlight::getFlights(string from, string from_date, string to,
    string to_date, int adults, int children) {
    std::vector<Flight*> result;
    for (auto& flight : AirCanadaOnlineAPI::GetFlights(from, from_date, to, to_date, adults, children)) {
        AirCanadaFlightAdapter* adapter = new AirCanadaFlightAdapter(flight);
        result.push_back(adapter);
    }
    return result;
}

void CanadaFlight::reserve(Flight& f, CustomerInfo& c) {
    AirCanadaCustomerAdapter customerAdapter(c);
    AirCanadaFlightAdapter flightAdapter(f);
    AirCanadaCustomerInfo apiCustomer = customerAdapter.toApi();
    AirCanadaFlight apiFlight = flightAdapter.toApi();
    AirCanadaOnlineAPI::ReserveFlight(apiFlight, apiCustomer);
}

// ===== TurkishFlights =====
std::string TurkishFlights::getName() {
    return "Turkish Flight";
}

Iitinerary* TurkishFlights::clone() {
    return new TurkishFlights(*this);
}

std::vector<Flight*> TurkishFlights::getFlights(string from, string from_date, string to,
    string to_date, int adults, int children) {
    std::vector<Flight*> result;
    for (auto& flight : TurkishAirlinesOnlineAPI::GetAvailableFlights()) {
        AirTurkishFlightAdapter* adapter = new AirTurkishFlightAdapter(flight);
        result.push_back(adapter);
    }
    return result;
}

void TurkishFlights::reserve(Flight& f, CustomerInfo& c) {
    AirTurkishCustomerAdapter customerAdapter(c);
    AirTurkishFlightAdapter flightAdapter(f);
    TurkishCustomerInfo apiCustomer = customerAdapter.toApi();
    TurkishFlight apiFlight = flightAdapter.toApi();
    TurkishAirlinesOnlineAPI::ReserveFlight(apiCustomer, apiFlight);
}

// ===== FlightManager =====
FlightManager::FlightManager() {
    objs.push_back(new CanadaFlight());
    objs.push_back(new TurkishFlights());
}

bool FlightManager::printSearchAll(std::string from, std::string fromDate, std::string to,
    std::string toDate, int adults, int children) {
    bool emp = true;
    for (auto obj : objs) {
        std::vector<Flight*> res = obj->search(from, fromDate, to, toDate, adults, children);
        obj->print(res);
        if (!res.empty()) emp = false;
        for (auto r : res)
            delete r;
    }
    return emp;
}

Flight* FlightManager::selectFlight(FlightItinerary*& selectedService, std::string from,
    std::string fromDate, std::string to, std::string toDate,
    int adults, int children) {
    std::string text;
    int choice;
    Flight* selectedFlight = nullptr;
    bool go = false;

    while (true) {
        std::cout << "Select A flight \"e.g Canada 2\": ";
        std::cin >> text >> choice;
        text = Utils::capitalize(text);
        choice--;

        for (auto obj : objs) {
            std::string flightName = obj->getName();
            flightName = flightName.substr(0, flightName.find(' '));

            if (flightName == text) {
                std::vector<Flight*> res = obj->search(from, fromDate, to, toDate, adults, children);

                if (!(choice >= 0 && choice < res.size())) {
                    std::cout << "Not valid number\n";
                    for (auto r : res)
                        delete r;
                    go = true;
                    break;
                }

                selectedFlight = new Flight(*(res[choice]));
                selectedService = obj;

                for (auto r : res)
                    delete r;

                return selectedFlight;
            }
        }

        if (go) {
            go = false;
            continue;
        }
        std::cout << "Not valid flight name\n";
    }
}

FlightManager::~FlightManager() {
    for (auto obj : objs)
        delete obj;
    objs.clear();
}

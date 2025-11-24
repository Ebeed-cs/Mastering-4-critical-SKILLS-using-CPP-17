// Header for Flight itinerary classes
#ifndef FLIGHTITENARY_H
#define FLIGHTITENARY_H

#include "Apis/expedia_flights_api.h"
#include "itinerary.h"
#include "FlightAndCustomerInfo.h"
#include "ItineraryItem.h"

class AirCanadaCustomerAdapter : public CustomerInfo {
public:
    AirCanadaCustomerAdapter(AirCanadaCustomerInfo& other);
    AirCanadaCustomerAdapter(CustomerInfo& other);
    AirCanadaCustomerInfo toApi();
};

class AirCanadaFlightAdapter : public Flight {
public:
    AirCanadaFlightAdapter(AirCanadaFlight& f);
    AirCanadaFlightAdapter(Flight& other);
    AirCanadaFlight toApi();
};

class AirTurkishCustomerAdapter : public CustomerInfo {
public:
    AirTurkishCustomerAdapter(TurkishCustomerInfo& other);
    AirTurkishCustomerAdapter(CustomerInfo& other);
    TurkishCustomerInfo toApi();
};

class AirTurkishFlightAdapter : public Flight {
public:
    AirTurkishFlightAdapter(TurkishFlight& f);
    AirTurkishFlightAdapter(Flight& other);
    TurkishFlight toApi();
};

class CanadaFlight : public FlightItinerary {
public:
    std::string getName() override;
    Iitinerary* clone() override;
    std::vector<Flight*> getFlights(string from = "", string from_date = "", string to = "",
        string to_date = "", int adults = 0, int children = 0);
    void reserve(Flight& f, CustomerInfo& c) override;
};

class TurkishFlights : public FlightItinerary {
public:
    std::string getName() override;
    Iitinerary* clone() override;
    std::vector<Flight*> getFlights(string from = "", string from_date = "", string to = "",
        string to_date = "", int adults = 0, int children = 0);
    void reserve(Flight& f, CustomerInfo& c) override;
};

class FlightManager {
private:
    std::vector<FlightItinerary*> objs;
public:
    FlightManager();
    bool printSearchAll(std::string from, std::string fromDate, std::string to, std::string toDate,
        int adults = 0, int children = 0);
    Flight* selectFlight(FlightItinerary*& selectedService, std::string from, std::string fromDate,
        std::string to, std::string toDate, int adults = 0, int children = 0);
    ~FlightManager();
};

#endif

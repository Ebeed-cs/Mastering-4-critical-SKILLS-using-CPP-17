// Header for Itinerary classes

#ifndef ITINERARY_H
#define ITINERARY_H

#include "Apis/expedia_hotels_api.h"
#include <vector>
#include "Utils.h"
#include "FlightAndCustomerInfo.h"

class Iitinerary {
public:
    virtual std::string getName() = 0;
    virtual Iitinerary* clone() = 0;
    virtual void cancel();
};

class HotelItinerary : public Iitinerary {
public:
    virtual void reserve();
    virtual void print(std::vector<RoomBase*>& rooms) = 0; // print the satisfying results 
    virtual std::vector<RoomBase*> search(std::string country, std::string city, std::string from_date, std::string to_date, int needed_rooms) = 0;
};

class FlightItinerary : public Iitinerary {
public:
    virtual void reserve(Flight& f, CustomerInfo& c) = 0;
    virtual std::vector<Flight*> getFlights(std::string from = "", std::string from_date = "", std::string to = "", std::string to_date = "", int adults = 0, int children = 0) = 0;
    virtual std::vector<Flight*> search(std::string from, std::string fromDate, std::string to, std::string toDate, int adults = 0, int children = 0);
    virtual void print(std::vector<Flight*> flights);
};

#endif

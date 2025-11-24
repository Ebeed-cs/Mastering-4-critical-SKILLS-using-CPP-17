// Header for ItineraryItem, FlightItem, and HotelItem classes

#ifndef ITINERARYITEM_H
#define ITINERARYITEM_H

#include "FlightAndCustomerInfo.h"
#include "itinerary.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>

using namespace std;

class ItineraryItem {
protected:
    double cost;
public:
    virtual ~ItineraryItem() {}
    virtual double getCost() const = 0;
    virtual ItineraryItem* clone() const = 0;
    virtual void cancel() = 0;
    virtual void reserve() = 0;
    virtual void printItem() const = 0;
    virtual std::string getItemType() const = 0;
    virtual std::string getItemSummary() const = 0;
};

class FlightItem : public ItineraryItem {
private:
    Flight* clientFlight;
    FlightItinerary* service;
    CustomerInfo* customerinfo;

    void Clear();
    std::string getItemType() const override;

public:
    FlightItem(Flight* f, FlightItinerary* s, CustomerInfo* c);
    FlightItem(const FlightItem& other);
    std::string getItemSummary() const override;
    FlightItem& operator=(const FlightItem& other);
    ItineraryItem* clone() const override;
    double getCost() const override;
    void cancel() override;
    void reserve() override;
    void printItem() const override;
    ~FlightItem();
};

class HotelItem : public ItineraryItem {
private:
    RoomBase* clientRoom;
    CustomerInfo* customerinfo;
    HotelItinerary* service;
    int nights;

    void Clear();
    std::string getItemType() const override;

public:
    HotelItem(RoomBase* r, CustomerInfo* c, HotelItinerary* s);
    HotelItem(const HotelItem& other);
    std::string getItemSummary() const override;
    HotelItem& operator=(const HotelItem& other);
    ItineraryItem* clone() const override;
    double getCost() const override;
    void reserve() override;
    void cancel() override;
    void printItem() const override;
    ~HotelItem();
};

#endif

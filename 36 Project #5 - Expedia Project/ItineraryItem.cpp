// Implementation for ItineraryItem, FlightItem, and HotelItem classes

#include "ItineraryItem.h"

// ==================== FlightItem ====================

void FlightItem::Clear() {
    delete clientFlight;
    delete service;
    delete customerinfo;
    clientFlight = nullptr;
    service = nullptr;
    customerinfo = nullptr;
}

std::string FlightItem::getItemType() const {
    return "Flight";
}

FlightItem::FlightItem(Flight* f, FlightItinerary* s, CustomerInfo* c)
    : clientFlight(new Flight(*f)),
    service(dynamic_cast<FlightItinerary*>(s->clone())),
    customerinfo(new CustomerInfo(*c)) {
    cost = clientFlight->price;
}

FlightItem::FlightItem(const FlightItem& other)
    : clientFlight(new Flight(*(other.clientFlight))),
    service(dynamic_cast<FlightItinerary*>(other.service->clone())),
    customerinfo(new CustomerInfo(*(other.customerinfo))) {
    cost = other.cost;
}

std::string FlightItem::getItemSummary() const {
    return "Flight: " + clientFlight->from + " To " +
        clientFlight->to + " ($" +
        std::to_string((int)clientFlight->price) + ")";
}

FlightItem& FlightItem::operator=(const FlightItem& other) {
    if (this != &other) {
        Clear();
        clientFlight = new Flight(*(other.clientFlight));
        service = dynamic_cast<FlightItinerary*>(other.service->clone());
        customerinfo = new CustomerInfo(*(other.customerinfo));
        cost = other.cost;
    }
    return *this;
}

ItineraryItem* FlightItem::clone() const {
    return new FlightItem(*this);
}

double FlightItem::getCost() const {
    return cost;
}

void FlightItem::cancel() {
    service->cancel();
}

void FlightItem::reserve() {
    service->reserve(*clientFlight, *customerinfo);
}

void FlightItem::printItem() const {
    cout << "\n========================================\n";
    cout << "        FLIGHT RESERVATION\n";
    cout << "========================================\n";
    cout << "Service      : " << service->getName() << "\n";
    cout << "From         : " << clientFlight->from << "\n";
    cout << "To           : " << clientFlight->to << "\n";
    cout << "Departure    : " << clientFlight->date_time_from << "\n";
    cout << "Arrival      : " << clientFlight->date_time_to << "\n";
    cout << "Price        : $" << fixed << setprecision(2) << clientFlight->price << "\n";
    cout << "========================================\n";
}

FlightItem::~FlightItem() {
    Clear();
}

// ==================== HotelItem ====================

void HotelItem::Clear() {
    delete clientRoom;
    delete service;
    delete customerinfo;
    clientRoom = nullptr;
    service = nullptr;
    customerinfo = nullptr;
}

std::string HotelItem::getItemType() const {
    return "Hotel";
}

HotelItem::HotelItem(RoomBase* r, CustomerInfo* c, HotelItinerary* s)
    : clientRoom(new RoomBase(*r)),
    service(dynamic_cast<HotelItinerary*>(s->clone())),
    customerinfo(new CustomerInfo(*c)),
    nights(0) {
    nights = Utils::calcNights(clientRoom->date_from, clientRoom->date_to);
    cost = clientRoom->price_per_night * nights;
}

HotelItem::HotelItem(const HotelItem& other)
    : clientRoom(new RoomBase(*(other.clientRoom))),
    service(dynamic_cast<HotelItinerary*>(other.service->clone())),
    customerinfo(new CustomerInfo(*(other.customerinfo))),
    nights(other.nights) {
    cost = other.cost;
}

std::string HotelItem::getItemSummary() const {
    return "Hotel: " + service->getName() + " in " +
        clientRoom->city + " (" + std::to_string(nights) +
        " nights, $" + std::to_string((int)cost) + ")";
}

HotelItem& HotelItem::operator=(const HotelItem& other) {
    if (this != &other) {
        Clear();
        clientRoom = new RoomBase(*(other.clientRoom));
        service = dynamic_cast<HotelItinerary*>(other.service->clone());
        customerinfo = new CustomerInfo(*(other.customerinfo));
        nights = other.nights;
        cost = other.cost;
    }
    return *this;
}

ItineraryItem* HotelItem::clone() const {
    return new HotelItem(*this);
}

double HotelItem::getCost() const {
    return cost;
}

void HotelItem::reserve() {
    service->reserve();
}

void HotelItem::cancel() {
    service->cancel();
}

void HotelItem::printItem() const {
    cout << "\n========================================\n";
    cout << "         HOTEL RESERVATION\n";
    cout << "========================================\n";
    cout << "Hotel        : " << service->getName() << "\n";
    cout << "Room Type    : " << clientRoom->room_type << "\n";
    cout << "Location     : " << clientRoom->city << ", " << clientRoom->country << "\n";
    cout << "Check-in     : " << clientRoom->date_from << "\n";
    cout << "Check-out    : " << clientRoom->date_to << "\n";
    cout << "Nights       : " << nights << "\n";
    cout << "Per Night    : $" << fixed << setprecision(2) << clientRoom->price_per_night << "\n";
    cout << "Total        : $" << fixed << setprecision(2) << getCost() << "\n";
    cout << "========================================\n";
}

HotelItem::~HotelItem() {
    Clear();
}

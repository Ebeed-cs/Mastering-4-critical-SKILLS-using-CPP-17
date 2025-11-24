// Implementation for Hotel Itinerary classes

#include "HotelItenary.h"
#include <iostream>

Iitinerary* HiltonHotel::clone() {
    return new HiltonHotel(*this);
}

std::string HiltonHotel::getName() {
    return "Hilton Hotel";
}

std::vector<RoomBase*> HiltonHotel::search(std::string country, std::string city, std::string from_date, std::string to_date, int needed_rooms) {
    std::vector<RoomBase*> result;
    for (auto v : HiltonHotelAPI::SearchRooms(country, city, from_date, to_date, needed_rooms))
        result.push_back(new HiltonRoom(v));
    return result;
}

void HiltonHotel::print(std::vector<RoomBase*>& rooms) {
    std::vector<HiltonRoom> result;
    for (auto room : rooms) {
        if (HiltonRoom* ptr = dynamic_cast<HiltonRoom*>(room))
            result.push_back(*ptr);
    }
    HiltonHotelAPI::print(result);
}

Iitinerary* MarriottHotel::clone() {
    return new MarriottHotel(*this);
}

void MarriottHotel::print(std::vector<RoomBase*>& rooms) {
    std::vector<MarriottFoundRoom> result;
    for (auto room : rooms) {
        if (MarriottFoundRoom* ptr = dynamic_cast<MarriottFoundRoom*>(room))
            result.push_back(*ptr);
    }
    MarriottHotelAPI::print(result);
}

std::string MarriottHotel::getName() {
    return "Marriott Hotel";
}

std::vector<RoomBase*> MarriottHotel::search(std::string country, std::string city, std::string from_date, std::string to_date, int needed_rooms) {
    std::vector<RoomBase*> result;
    for (auto v : MarriottHotelAPI::FindRooms(from_date, to_date, country, city, needed_rooms))
        result.push_back(new MarriottFoundRoom(v));
    return result;
}

HotelManager::HotelManager() {
    objs.push_back(new HiltonHotel());
    objs.push_back(new MarriottHotel());
}

bool HotelManager::printSearchAll(std::string country, std::string city, std::string from_date, std::string to_date, int needed_rooms) {
    bool emp = true;
    for (auto obj : objs) {
        std::vector<RoomBase*> res = obj->search(country, city, from_date, to_date, needed_rooms);
        obj->print(res);
        if (res.size()) emp = false;
        for (auto r : res)
            delete r;
    }
    return emp;
}

RoomBase* HotelManager::selectHotel(HotelItinerary*& selectedService,
    std::string country, std::string city,
    std::string from_date, std::string to_date, int needed_rooms) {
    std::string text;
    int choice;
    RoomBase* selectedRoom = nullptr;
    bool go = false;

    while (true) {
        std::cout << "Select A hotel \"e.g Hilton 2\": ";
        std::cin >> text >> choice;
        text = Utils::capitalize(text);
        choice--;

        for (auto obj : objs) {
            std::string hotelName = obj->getName();
            hotelName = hotelName.substr(0, hotelName.find(' '));

            if (hotelName == text) {
                std::vector<RoomBase*> res = obj->search(country, city, from_date, to_date, needed_rooms);

                if (!(choice >= 0 && choice < res.size())) {
                    std::cout << "Not valid number\n";
                    for (auto r : res)
                        delete r;
                    go = true;
                    break;
                }

                selectedRoom = new RoomBase(*(res[choice]));
                selectedService = obj;

                for (auto r : res)
                    delete r;

                return selectedRoom;
            }
        }

        if (go) {
            go = false;
            continue;
        }
        std::cout << "Not valid hotel name\n";
    }
}

HotelManager::~HotelManager() {
    for (auto obj : objs)
        delete obj;
    objs.clear();
}

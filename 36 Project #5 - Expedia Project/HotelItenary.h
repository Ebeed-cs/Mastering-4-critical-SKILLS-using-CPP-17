// Header for Hotel Itinerary classes

#ifndef HOTELITENARY_H
#define HOTELITENARY_H

#include "itinerary.h"

class HiltonHotel : public HotelItinerary {
public:
    virtual Iitinerary* clone() override;
    virtual std::string getName() override;
    virtual std::vector<RoomBase*> search(std::string country, std::string city, std::string from_date, std::string to_date, int needed_rooms) override;
    virtual void print(std::vector<RoomBase*>& rooms) override;
};

class MarriottHotel : public HotelItinerary {
public:
    virtual Iitinerary* clone() override;
    virtual void print(std::vector<RoomBase*>& rooms) override;
    virtual std::string getName() override;
    virtual std::vector<RoomBase*> search(std::string country, std::string city, std::string from_date, std::string to_date, int needed_rooms) override;
};

class HotelManager {
private:
    std::vector<HotelItinerary*> objs;

public:
    HotelManager();
    bool printSearchAll(std::string country, std::string city, std::string from_date, std::string to_date, int needed_rooms = 0);
    RoomBase* selectHotel(HotelItinerary*& selectedService,
        std::string country, std::string city,
        std::string from_date, std::string to_date, int needed_rooms = 0);
    ~HotelManager();
};

#endif

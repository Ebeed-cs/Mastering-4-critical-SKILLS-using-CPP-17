// Header for Flight and CustomerInfo classes
#ifndef FLIGHTANDCUSTOMERINFO_H
#define FLIGHTANDCUSTOMERINFO_H

#include <iostream>
#include <string>

//                                              Adapter Pattern

// base classes
class CustomerInfo {
public:
    std::string userName;
    std::string name;
    std::string email;
    int adults;
    int children;
    int infants;

    CustomerInfo();
    virtual ~CustomerInfo();
};

class Flight {
public:
    double price;
    std::string date_time_from;
    std::string date_time_to;
    std::string from;
    std::string to;

    Flight();
    void read();
    virtual ~Flight();
};

#endif

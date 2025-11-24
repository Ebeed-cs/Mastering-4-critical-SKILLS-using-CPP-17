// Header for Utils namespace and related utilities

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>

namespace Utils {

    int toInt(std::string str);

    struct DateParts {
        std::string day;
        std::string month;
        std::string year;

        DateParts(const std::string& date);
    };

    std::string capitalize(std::string input);
    int calcNights(std::string checkin, std::string checkout);

}

#endif

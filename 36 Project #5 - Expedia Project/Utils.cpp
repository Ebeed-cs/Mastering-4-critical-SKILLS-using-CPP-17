// Implementation for Utils namespace and related utilities

#include "Utils.h"
#include <stdexcept>
#include <cctype>

namespace Utils {

    int toInt(std::string str) {
        std::istringstream oss(str);
        int num;
        oss >> num;
        return num;
    }

    DateParts::DateParts(const std::string& date) {
        if (date == ".") {
            day = month = year = ".";
            return;
        }
        if (date.size() < 10) {
            throw std::invalid_argument("Invalid date format: " + date);
        }
        day = date.substr(0, 2);
        month = date.substr(3, 2);
        year = date.substr(6, 4);
    }

    std::string capitalize(std::string input) {
        std::string result;
        result += toupper(input[0]);
        for (int i = 1; i < input.length(); ++i)
            result += tolower(input[i]);
        return result;
    }

    int calcNights(std::string checkin, std::string checkout) {
        Utils::DateParts in(checkin);
        Utils::DateParts out(checkout);

        int nights = 0;
        nights += (toInt(out.year) - toInt(in.year)) * 360;
        nights += (toInt(out.month) - toInt(in.month)) * 30;
        nights += (toInt(out.day) - toInt(in.day));

        return nights;
    }

}

#include <iostream>
#include <vector>
#include "User.h"
#include <cassert>
#include "AskMeSystem.h"
#include "Utils.h"


void UsersManager::fetchLinesUsers(std::vector<std::string>& fileLines, std::string delimeter) {
    if (fileLines.empty()) {
        std::cout << "No users to load from file." << std::endl;
        return;
    }

    for (const auto& line : fileLines) {
        if (line.empty()) continue; // Skip empty lines

        std::vector<std::string> info;
        std::string tempLine = line + delimeter;

        while (tempLine.length() > 0) {
            size_t pos = tempLine.find(delimeter);
            if (pos == std::string::npos) break;

            std::string field = tempLine.substr(0, pos);
            info.push_back(field);
            tempLine.erase(0, pos + delimeter.length());
        }

        // Only create user if we have enough data
        if (info.size() >= 4) {
            addUser(new User(info));
        }
    }
}

void UsersManager::usersLoad() {
    if (users.size()) {
        for (auto& user : users)
            delete user;
        users.clear();
    }

    std::vector<std::string> fileLines;
    Utils::readFile(inAndOutFiles::inAndOutUsers, fileLines);
    fetchLinesUsers(fileLines);
}

bool UsersManager::isAnonymous(int id) {
    for (auto* user : users) {
        if (user->getId() == id) {
            return user->isAnonymous();
        }
    }
    throw std::invalid_argument("User with ID " + Utils::toString(id) + " not found");
}

UsersManager::UsersManager() {
    usersLoad();
}

UsersManager::~UsersManager() {
    for (auto& user : users)
        delete user;
    users.clear();
}


void UsersManager::addUser(User* newUser) {
    users.push_back(newUser);
}

std::vector<User*>& UsersManager::getUsers() {
    return users;
}

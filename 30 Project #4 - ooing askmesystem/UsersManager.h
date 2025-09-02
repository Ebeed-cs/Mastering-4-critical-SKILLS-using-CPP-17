#ifndef USERSMANAGER_H
#define USERSMANAGER_H

#include "User.h"

class UsersManager {
    std::vector<User*> users;
    void fetchLinesUsers(std::vector<std::string>& fileLines, std::string delimeter = ",");
public:
    std::vector<User*>& getUsers();
    UsersManager();
    ~UsersManager();
    void usersLoad();
    void addUser(User* newUser);
    bool isAnonymous(int id);
};

#endif
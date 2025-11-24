// Header for UsersManager class

#ifndef USERSMANAGER_H
#define USERSMANAGER_H

#include "User.h"
#include <vector>
#include <string>

class UsersManager {
private:
    std::vector<User*> users;
    User* currentUser = nullptr;

public:
    UsersManager();
    UsersManager(UsersManager& other);
    UsersManager& operator=(UsersManager& other);
    ~UsersManager();

    void addUsers(User* u);
    void setCurrentUser(User* u);
    User* getCurrentUser() const;
    std::vector<User*>& getUsersVector();
    void Clear();
    User* searchUsers(std::string userName, std::string password);
};

#endif

// Implementation for UsersManager class

#include "UserManagers.h"

UsersManager::UsersManager() = default;

UsersManager::UsersManager(UsersManager& other) {
    for (auto& user : other.users)
        users.push_back(user->Clone());
    currentUser = (other.currentUser)->Clone();
}

UsersManager& UsersManager::operator=(UsersManager& other) {
    Clear();
    for (auto& user : other.users)
        users.push_back(user->Clone());

    currentUser = (other.currentUser)->Clone();

    return *this;
}

void UsersManager::addUsers(User* u) {
    users.push_back(u->Clone());
}

void UsersManager::setCurrentUser(User* u) {
    currentUser = u;
}

User* UsersManager::getCurrentUser() const {
    return currentUser;
}

std::vector<User*>& UsersManager::getUsersVector() {
    return users;
}

void UsersManager::Clear() {
    for (auto& user : users)
        delete user;
    users.clear();

    // delete currentUser; // will clear by the previous for loop
    // currentUser = nullptr;
}

User* UsersManager::searchUsers(std::string userName, std::string password) {
    for (auto& user : users)
        if (user->getUserName() == userName && user->getPassword() == password)
            return user;
    return nullptr;
}

UsersManager::~UsersManager() {
    Clear();
}

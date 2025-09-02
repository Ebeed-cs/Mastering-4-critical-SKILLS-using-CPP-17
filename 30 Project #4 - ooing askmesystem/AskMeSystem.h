#ifndef ASKMESYSTEM_H
#define ASKMESYSTEM_H


#include <string>
#include <vector>              
#include "UsersManager.h"      
#include "QuestionsManager.h"

namespace inAndOutFiles
{
    extern std::string inAndOutUsers;
    extern std::string inAndOutQuestions;
} // namespace inAndOutFiles



class AskMeSystem {
    UsersManager usersManager{};
    QuestionsManager questionsManager{};
    User* currentUser = nullptr;
    std::vector<std::string> registration = { "Login" , "SignUp" };
    std::vector<std::string> order = { "Print Questions To Me" , "Print Questions From Me" , "Answer Question" , "Delete Question" , "Ask Question" , "List System Users" , "Feed" , "LogOut" };
    int display(const std::vector<std::string>& menu);
    int userInput(int maxRange, int minRange = 1);
    void handleAuthentication();
    void handelMenu(int input);
    void handelSignUp(std::vector<std::string>& info);
    void handelLogin(std::pair<std::string, std::string>& p);
    User* checkUser(const std::vector<User*>& userAddresses);
    void handelAsk(std::vector<std::string>& iQuestion);
    void printToMe();
    void printFromMe();
    void listSystemUsers();
    void answerQuestion();
    void feed();
    void deleteQuestion();

public:
    AskMeSystem();
    void login();
    void signup();
    void load();
    void signout();
    void run();
    void menu();
    void AskQuestion();
    ~AskMeSystem();
};

#endif

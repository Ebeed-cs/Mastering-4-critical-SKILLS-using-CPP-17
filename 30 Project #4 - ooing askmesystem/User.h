#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <map>
#include "Question.h"

class User {
    int id;
    std::string username;
    std::string password;
    std::string name;
    int aonymous_questions;
    void goToFile(const std::vector<std::string>& info);
    void addQuestionFromMe(Question* q, const std::map<Question*, std::vector<Question*>>& questions);
    void addQuestionToMe(Question* q, const std::map<Question*, std::vector<Question*>>& questions);
public:
    std::map<Question*, std::vector<Question*>> questionsFromMe;
    std::map<Question*, std::vector<Question*>> questionsToMe;
    std::map<Question*, std::vector<Question*>>& getQuestionsFromMe();
    void searchQuestions(const std::map<Question*, std::vector<Question*>>& questions);
    bool isAnonymous();
    User(std::vector<std::string> info);
    void printFromMe(std::vector<bool>& isAnonymous);
    void printToMe();
    int getId();
    std::string getUsername();
    std::string getPassword();
    std::string getName();
};

#endif
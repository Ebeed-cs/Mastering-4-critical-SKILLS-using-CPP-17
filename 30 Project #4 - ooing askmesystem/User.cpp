#include <iostream>
#include "User.h"
#include "Utils.h"
#include <fstream>
#include "AskMeSystem.h"
#include <cassert>


bool User::isAnonymous() {
    return aonymous_questions;
}

void User::printToMe() {
    for (auto& [questionParent, threadVector] : questionsToMe) {
        // Add null pointer check
        if (!questionParent) {
            std::cout << "Error: Null parent question found\n";
            continue;
        }

        std::cout << "Question id(" << questionParent->getId() << ") "
            << "from user id(" << questionParent->getFromId() << ")        "
            << "Question: " << questionParent->getQuestionText() << "\n";
        std::cout << "      Answer: " << questionParent->getAnswer() << "\n";

        for (auto* threadParent : threadVector) {
            // Add null pointer check for thread questions too
            if (!threadParent) {
                std::cout << "Error: Null thread question found\n";
                continue;
            }

            std::cout << "Thread:   ";
            std::cout << "Question id(" << threadParent->getId() << ") "
                << "from user id(" << threadParent->getFromId() << ")        "
                << "Question: " << threadParent->getQuestionText() << "\n";
            std::cout << "      Answer: " << threadParent->getAnswer() << "\n\n";
        }
    }
}

std::map<Question*, std::vector<Question*>>& User::getQuestionsFromMe() {
    return questionsFromMe;
}

void User::printFromMe(std::vector<bool>& isAnonymous) {
    int index = 0;
    for (auto& [parentQuestion, threadQuestions] : questionsFromMe) {
        bool anonymous = (index < isAnonymous.size()) ? isAnonymous[index] : false;

        std::cout << "Question Id (" << parentQuestion->getId() << ") "
            << (anonymous ? "" : "!AQ ")
            << "to user id(" << parentQuestion->getToId() << ")"
            << " Question: " << parentQuestion->getQuestionText()
            << " Answer: " << parentQuestion->getAnswer() << "\n";

        for (auto& threadQuestion : threadQuestions) {
            std::cout << "  Thread: Question Id (" << threadQuestion->getId() << ") "
                << "to user id(" << threadQuestion->getToId() << ")"
                << " Question: " << threadQuestion->getQuestionText()
                << " Answer: " << threadQuestion->getAnswer() << "\n";
        }
        index++;
    }
}


void User::goToFile(const std::vector<std::string>& info) {
    std::vector<std::string> temp;
    temp.push_back(Utils::toString(id));
    for (int i = 0; i < info.size(); ++i)
        temp.push_back(info[i]);
    std::string line = Utils::inOneLine(temp);
    Utils::writeInFile(inAndOutFiles::inAndOutUsers, { line });
}

void User::addQuestionFromMe(Question* q, const std::map<Question*, std::vector<Question*>>& questions) {
    assert(q);

    if (q->getParent() == -1)
        questionsFromMe[q] = {};
    else
        questionsFromMe[Utils::getQuestion(q->getParent(), questions)].push_back(q);
}

void User::addQuestionToMe(Question* q, const std::map<Question*, std::vector<Question*>>& questions) {
    assert(q);

    if (q->getParent() == -1)
        questionsToMe[q] = {};
    else
        questionsToMe[Utils::getQuestion(q->getParent(), questions)].push_back(q);
}

void User::searchQuestions(const std::map<Question*, std::vector<Question*>>& questions) {
    // Clear existing questions to avoid duplicates
    questionsFromMe.clear();
    questionsToMe.clear();

    for (auto& [parentQuestion, threadQuestions] : questions) {
        if (!parentQuestion) continue;

        // Check parent question
        if (parentQuestion->getFromId() == id) {
            addQuestionFromMe(parentQuestion, questions);
        }
        if (parentQuestion->getToId() == id) {
            addQuestionToMe(parentQuestion, questions);
        }

        // Check thread questions
        for (auto* threadQuestion : threadQuestions) {
            if (!threadQuestion) continue;

            if (threadQuestion->getFromId() == id) {
                addQuestionFromMe(threadQuestion, questions);
            }
            if (threadQuestion->getToId() == id) {
                addQuestionToMe(threadQuestion, questions);
            }
        }
    }
}


User::User(std::vector<std::string> info) {
    int i = 0;
    id = Utils::generatId(inAndOutFiles::inAndOutUsers);
    if (info.size() > 4)
        id = Utils::toInt(info[i++]);
    username = info[i++];
    password = info[i++];
    name = info[i++];
    aonymous_questions = Utils::toInt(info[i++]);
    if (info.size() <= 4)
        goToFile(info);
}

int User::getId() {
    return id;
}

std::string User::getName() {
    return name;
}

std::string User::getPassword() {
    return password;
}

std::string User::getUsername() {
    return username;
}

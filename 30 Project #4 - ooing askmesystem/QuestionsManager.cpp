#include <iostream>
#include "Question.h"
#include <cassert>
#include <vector>
#include "Utils.h"
#include "QuestionsManager.h"
#include "AskMeSystem.h"
#include <sstream>


QuestionsManager::QuestionsManager() {
    questionsLoad();
}

void QuestionsManager::addQuestion(Question* q) {
    assert(q);

    if (q->getParent() == -1) {
        // This is a parent question
        questions[q] = {};
    }
    else {
        // This is a thread question
        Question* parentQuestion = getQuestionById(q->getParent());
        if (parentQuestion) {
            questions[parentQuestion].push_back(q);
        }
        else {
            std::cout << "Warning: Parent question with ID " << q->getParent()
                << " not found. Creating orphaned thread question.\n";
            // You might want to handle this case differently
            // For now, we'll skip adding this thread question
            delete q;
            return;
        }
    }
}

Question* QuestionsManager::getQuestionById(int id) {
    for (auto& [parentQuestion, threadQuestions] : questions) {
        if (parentQuestion->getId() == id)
            return parentQuestion;

        for (auto* threadQuestion : threadQuestions) {
            if (threadQuestion->getId() == id)
                return threadQuestion;
        }
    }
    return nullptr;
}

std::map<Question*, std::vector<Question*>>& QuestionsManager::getQuestions() {
    return questions;
}



void QuestionsManager::fetchLinesQuestions(std::vector<std::string>& fileLines, std::string delimeter) {
    if (fileLines.empty()) return;

    for (auto tempLine : fileLines) {
        if (tempLine.empty()) continue;

        std::vector<std::string> info;

        // Parse the line and populate info vector
        while (!tempLine.empty()) {
            size_t pos = tempLine.find(delimeter);
            if (pos == std::string::npos) {
                // Last field (no delimiter found)
                if (!tempLine.empty()) {
                    info.push_back(tempLine);
                }
                break;
            }

            std::string field = tempLine.substr(0, pos);
            info.push_back(field); // Add field to info vector
            tempLine.erase(0, pos + delimeter.length());
        }

        addQuestion(new Question(info, false));
        info.clear();
    }
}

void QuestionsManager::questionsLoad() {
    if (questions.size()) {
        for (auto& [parentQuestion, threadQuestions] : questions) {
            delete parentQuestion;
            for (auto* threadQuestion : threadQuestions) {
                delete threadQuestion;
            }
        }
        questions.clear();
    }

    std::vector<std::string>fileLines;
    Utils::readFile(inAndOutFiles::inAndOutQuestions, fileLines);
    fetchLinesQuestions(fileLines);
}

QuestionsManager::~QuestionsManager() {
    for (auto& [parentQuestion, threadQuestions] : questions) {
        delete parentQuestion;
        for (auto* threadQuestion : threadQuestions) {
            delete threadQuestion;
        }
    }
    questions.clear();
}

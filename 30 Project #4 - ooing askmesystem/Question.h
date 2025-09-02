#ifndef QUESTION_H
#define QUESTION_H

#include <vector>
class Question {
    int qParent;
    int qId;
    int fromId;
    int toId;
    std::string questionText;
    std::string answer;
    void updateQuestionInFile();
public:
    void deleteQuestion();
    Question(std::vector<std::string>& info, bool goFile = true);
    int getParent();
    int getId();
    void setAnswer(std::string newAnswer);
    int getFromId();
    int getToId();
    std::string getAnswer();
    std::string getQuestionText();
    void goToFile(const std::vector<std::string>& info);
};

#endif
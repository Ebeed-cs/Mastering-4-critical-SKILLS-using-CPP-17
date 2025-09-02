#ifndef QUESTIONSMANAGER_H
#define QUESTIONSMANAGER_H

#include <map>
#include <vector>

class QuestionsManager {
    std::map<Question*, std::vector<Question*>> questions;
public:
    Question* getQuestionById(int id);
    QuestionsManager();
    void questionsLoad();
    void fetchLinesQuestions(std::vector<std::string>& fileLines, std::string delimeter = ",");
    void addQuestion(Question* q);
    std::map<Question*, std::vector<Question*>>& getQuestions();
    ~QuestionsManager();
};

#endif 

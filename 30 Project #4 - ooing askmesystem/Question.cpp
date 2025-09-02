#include <iostream>
#include "Question.h"
#include "Utils.h"
#include "AskMeSystem.h"




Question::Question(std::vector<std::string>& info, bool goFile) {
    qParent = Utils::toInt(info[0]);
    qId = Utils::toInt(info[1]);
    fromId = Utils::toInt(info[2]);
    toId = Utils::toInt(info[3]);
    questionText = info[4];
    info.push_back("not answered yet");
    answer = info[5];

    if (goFile)
        goToFile(info);
}
void Question::setAnswer(std::string newAnswer) {
    answer = newAnswer;
    updateQuestionInFile();
}

void Question::updateQuestionInFile() {
    // Read all lines, update the specific question, write back
    std::vector<std::string> fileLines;
    Utils::readFile(inAndOutFiles::inAndOutQuestions, fileLines);

    // Update the line for this question
    for (auto& line : fileLines) {
        if (line.find(Utils::toString(qParent) + "," + Utils::toString(qId) + ",") == 0) { // the line which begin with "qId,"
            // This is our question line - rebuild it
            line = Utils::toString(qParent) + "," + Utils::toString(qId) + "," +
                Utils::toString(fromId) + "," +
                Utils::toString(toId) + "," +
                questionText + "," +
                answer;
            break;
        }
    }

    // Write updated lines back to file
    Utils::writeInFile(inAndOutFiles::inAndOutQuestions, fileLines, false);
}

void Question::deleteQuestion() {
    std::vector<std::string> fileLines;
    Utils::readFile(inAndOutFiles::inAndOutQuestions, fileLines);

    std::vector<std::string> updatedLines;

    for (const auto& line : fileLines) {
        if (line.empty()) continue;

        // Check if this line represents our question (parent or thread)
        // Format: qParent,qId,fromId,toId,questionText,answer
        bool shouldDelete = false;

        // Check if this is the question we want to delete
        if (line.find(Utils::toString(qParent) + "," + Utils::toString(qId) + ",") == 0) {
            shouldDelete = true; // This is our exact question
        }

        // Also delete any thread questions that have this question as parent
        if (line.find(Utils::toString(qId) + ",") == 0) {
            shouldDelete = true; // This is a thread of our question
        }

        if (!shouldDelete) {
            updatedLines.push_back(line);
        }
    }

    // Write updated lines back to file
    Utils::writeInFile(inAndOutFiles::inAndOutQuestions, updatedLines, false);
}

void Question::goToFile(const std::vector<std::string>& info) {
    std::string line = Utils::inOneLine(info);
    Utils::writeInFile(inAndOutFiles::inAndOutQuestions, { line });
}

int Question::getParent() {
    return qParent;
}

int Question::getId() {
    return qId;
}

int Question::getFromId() {
    return fromId;
}

int Question::getToId() {
    return toId;
}

std::string Question::getAnswer() {
    return answer;
}

std::string Question::getQuestionText() {
    return questionText;
}

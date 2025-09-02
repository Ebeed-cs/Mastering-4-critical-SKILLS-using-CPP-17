#include "AskMeSystem.h"
#include <iostream>
#include <utility>
#include "Utils.h"
#include <limits>
#include <cassert>

enum Order { TOME = 1, FROMME, ANSWER, DELETE, ASK, LIST, FEED, LOGOUT };

AskMeSystem::AskMeSystem() {
    // Constructor
}

AskMeSystem::~AskMeSystem() {
    // Destructor
}


void AskMeSystem::AskQuestion() {
    std::vector<std::string> infoQuestion(5);
    handelAsk(infoQuestion);

    // Check if the vector was cleared (user cancelled)
    if (infoQuestion.size() == 0) {
        std::cout << "Question cancelled.\n";
        return;
    }

    // Additional safety check before accessing elements
    if (infoQuestion.size() < 5) {
        std::cout << "Error: Incomplete question data.\n";
        return;
    }

    questionsManager.addQuestion(new Question(infoQuestion)); // will put the question in the last file not in it's place "if the question is a thread"

}

void AskMeSystem::handelAsk(std::vector<std::string>& iQuestion) {
    iQuestion[0] = Utils::toString(-1);
    iQuestion[1] = Utils::toString((Utils::generatId(inAndOutFiles::inAndOutQuestions)));
    iQuestion[2] = Utils::toString(currentUser->getId());

    std::cout << "Enter User id or -1 to cancel: ";
    std::cin >> iQuestion[3];

    if (Utils::toInt(iQuestion[3]) == -1) {
        iQuestion.clear();  // This makes size() = 0
        return;
    }

    if (!(usersManager.isAnonymous(Utils::toInt(iQuestion[3])))) {
        std::cout << "Note: Anonymous questions are not allowed for this user\n";
    }

    int input;
    std::cout << "for thread question: Enter the Question id or -1 for new question: ";
    std::cin >> input;

    if (input != -1) {
        Question* question = questionsManager.getQuestionById(input);
        assert(question);
        iQuestion[0] = Utils::toString(question->getId());
    }

    std::cout << "Enter question text: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, iQuestion[4]);

}

namespace inAndOutFiles
{
    std::string inAndOutUsers = "users.txt";
    std::string inAndOutQuestions = "questions.txt";
}


int AskMeSystem::display(const std::vector<std::string>& menu) {
    for (int i = 0; i < menu.size(); ++i)
        std::cout << i + 1 << " : " << menu[i] << "\n";

    return userInput(menu.size());
}

int AskMeSystem::userInput(int maxRange, int minRange) {
    int input;
    std::cout << "Enter number in range " << minRange << " - " << maxRange << ":";
    std::cin >> input;

    while (input < minRange || input > maxRange) {
        std::cout << "Error invalid number ... Try again" << "\n";
        std::cout << "Enter number in range " << minRange << " - " << maxRange << ":";
        std::cin >> input;
    }

    return input;
}

void AskMeSystem::listSystemUsers() {
    for (auto& user : usersManager.getUsers())
        std::cout << "ID: " << user->getId() << "  " << user->getName() << "\n";
}

void AskMeSystem::handelSignUp(std::vector<std::string>& info) {
    std::cout << "Enter user name. (No spaces):";
    std::cin >> info[0];

    std::cout << "Enter password:";
    std::cin >> info[1];

    std::cout << "Enter name:";
    std::cin >> info[2];

    std::cout << "Allow anonymous questions?: (0 or 1)";
    std::cin >> info[3];
}

void AskMeSystem::signup() {
    std::vector<std::string> result(4, "");
    handelSignUp(result);
    usersManager.addUser(new User(result));
    currentUser = usersManager.getUsers().back();
}

void AskMeSystem::signout() {
    std::cout << "User: " << currentUser->getName() << " go out" << "\n";
}

void AskMeSystem::handelLogin(std::pair<std::string, std::string>& p) {
    std::cout << "Enter user name & password: ";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cin >> p.first >> p.second;
}

User* AskMeSystem::checkUser(const std::vector<User*>& userAddresses) {
    std::pair<std::string, std::string>p;
    handelLogin(p);
    for (auto user : userAddresses)
        if (user->getUsername() == p.first && user->getPassword() == p.second)
            return user;
    return nullptr;
}

void AskMeSystem::login() {
    load();
    std::vector<User*>& userAddresses = usersManager.getUsers();
    User* user = nullptr;
    while (!(user = checkUser(userAddresses))) {
        std::cout << "Invalid Email or Password" << "\n";
        load();
    }
    currentUser = user;
}

void AskMeSystem::load() {
    int id = -1;
    if (currentUser != nullptr)
        id = currentUser->getId();

    usersManager.usersLoad();
    questionsManager.questionsLoad();

    if (id != -1)
        for (auto& user : usersManager.getUsers())
            if (user->getId() == id) {
                currentUser = user;
                break;
            }
}

void AskMeSystem::answerQuestion() {
    int id;
    std::cout << "Enter Question id or -1 to cancel: ";
    std::cin >> id;
    Question* q = questionsManager.getQuestionById(id);

    if (q == nullptr) {
        std::cout << "question cancled" << "\n";
        return;
    }
    if (q->getToId() != currentUser->getId()) {
        std::cout << "not asked to you" << "\n";
        return;
    }
    std::cout << "Question Id (" << id << ") from user id (";
    std::cout << q->getFromId() << ")       Question: " << q->getQuestionText() << "\n";
    std::cout << "       Answer: " << q->getAnswer() << "\n\n";

    if (q->getAnswer() != "not answered yet")
        std::cout << "Warning: Already answered , will be updated" << "\n";

    std::string answer;
    std::cout << "Enter answer: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, answer);
    q->setAnswer(answer);
}

void AskMeSystem::handleAuthentication() {
    if (display(registration) == 1)
        login();
    else
        signup();
}

void AskMeSystem::deleteQuestion() {
    int id;
    std::cout << "Enter id question or -1 to cancel: ";
    std::cin >> id;

    if (id == -1) {
        std::cout << "deletion canceled" << "\n";
        return;
    }

    Question* q = questionsManager.getQuestionById(id);

    if (q == nullptr) {
        std::cout << "the question not found" << "\n";
        return;
    }

    if (q->getFromId() != currentUser->getId()) {
        std::cout << "not asked by you" << "\n";
        return;
    }

    q->deleteQuestion();

}

void AskMeSystem::printToMe() {
    currentUser->searchQuestions(questionsManager.getQuestions());
    currentUser->printToMe();
}

void AskMeSystem::feed() {
    for (auto& [questionParent, threadVector] : questionsManager.getQuestions()) {
        std::cout << "Question Id (" << questionParent->getId() << ") from user id(" << questionParent->getFromId() << ") " << "to user id(" << questionParent->getToId() << ")";

        std::cout << "      Question: " << questionParent->getQuestionText() << "\n";

        std::cout << "      Answer: " << questionParent->getAnswer() << "\n";

        for (auto& threadQuestion : threadVector) {
            std::cout << "Thread:   ";
            std::cout << "Question Id (" << threadQuestion->getId() << ") from user id(" << threadQuestion->getFromId() << ") " << "to user id(" << threadQuestion->getToId() << ")";

            std::cout << "      Question: " << threadQuestion->getQuestionText() << "\n";

            std::cout << "      Answer: " << threadQuestion->getAnswer() << "\n";
        }

    }
}

void AskMeSystem::printFromMe() {
    std::vector<bool> Anonymous;
    currentUser->searchQuestions(questionsManager.getQuestions());

    for (auto& [parentQuestion, threadVector] : currentUser->getQuestionsFromMe())
        Anonymous.push_back(usersManager.isAnonymous(parentQuestion->getToId()));

    currentUser->printFromMe(Anonymous);
}

void AskMeSystem::handelMenu(int input) {
    load();
    switch (input)
    {
    case TOME:
        printToMe();
        break;
    case FROMME:
        printFromMe();
        break;
    case ANSWER:
        answerQuestion();
        break;
    case DELETE:
        deleteQuestion();
        break;
    case ASK:
        AskQuestion();
        break;
    case LIST:
        listSystemUsers();
        break;
    case FEED:
        feed();
        break;
    }
    load();
}
void AskMeSystem::menu() {
    handleAuthentication();
    int input = display(order);
    while (input != LOGOUT) {
        handelMenu(input);
        input = userInput(order.size());
    }
    signout();

}


void AskMeSystem::run() {
    menu();
}

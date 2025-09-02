#include <string>
#include <vector>
#include <map>
#include "Question.h"

namespace Utils
{
    int toInt(std::string str);

    void readFile(std::string path, std::vector<std::string>& fileLines);

    std::string toString(int num);

    std::string inOneLine(const std::vector<std::string>& temp, std::string delimeter = ",");

    std::string lastLine(std::string path);

    int generatId(std::string path, std::string delimeter = ",");

    void writeInFile(std::string path, const std::vector<std::string>& v, bool app = true);

    Question* getQuestion(int id, const std::map<Question*, std::vector<Question*>>& questions);
} // namespace Utils 


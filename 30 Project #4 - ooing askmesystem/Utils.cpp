#include "Utils.h"
#include <iostream>
#include <sstream>  
#include <fstream>
#include <vector>
#include <cassert>
#include <map>

namespace Utils
{
    int toInt(std::string str) {
        int line;
        std::istringstream iss(str);
        iss >> line;
        return line;
    }

    void readFile(std::string path, std::vector<std::string>& fileLines) {
        std::ifstream fin(path);

        if (fin.fail()) {
            std::cout << "the file " << path << " not opened " << "\n";
            return;
        }

        std::string line;
        while (std::getline(fin, line))
            fileLines.push_back(line);

        fin.close();
    }

    std::string toString(int num) {
        std::ostringstream oss;
        oss << num;
        return oss.str();
    }

    std::string inOneLine(const std::vector<std::string>& temp, std::string delimeter) {
        std::ostringstream oss;
        for (int i = 0; i < temp.size(); ++i) {
            oss << temp[i];
            if (i != temp.size() - 1)
                oss << delimeter;
        }
        return oss.str();
    }

    std::string lastLine(std::string path) {
        std::ifstream fin(path, std::ios::ate);

        if (fin.fail()) {
            std::cout << "the file " << path << " not opened" << "\n";
            return "";
        }

        auto fileSize = static_cast<long long>(fin.tellg());

        char ch;
        std::string lastLine = "";

        while (fileSize > 0) {
            fin.seekg(fileSize - 1);
            fin.get(ch);
            if (ch != '\n' && ch != '\r') break;
            --fileSize;
        }

        for (long long i = fileSize - 1; i >= 0; --i) {
            fin.seekg(i);
            fin.get(ch);

            if (ch == '\n') break;
            lastLine.insert(lastLine.begin(), ch);
        }
        return lastLine;

    }

    int generatId(std::string path, std::string delimeter) {
        std::string line = lastLine(path);
        if (line.length() == 0) return 1; // Start from 1, not 0

        // Handle different file formats
        if (path.find("users.txt") != std::string::npos) {
            // users.txt: id is first field
            size_t pos = line.find(delimeter);
            return (toInt(line.substr(0, (int)pos)) + 1);
        }
        else if (path.find("questions.txt") != std::string::npos) {
            // questions.txt: qId is second field (parentId,qId,...)
            size_t firstPos = line.find(delimeter);
            if (firstPos == std::string::npos) return 1;

            size_t secondPos = line.find(delimeter, firstPos + 1);
            if (secondPos == std::string::npos) return 1;

            std::string qIdStr = line.substr(firstPos + 1, secondPos - firstPos - 1);
            return (toInt(qIdStr) + 1);
        }

        // Default behavior for other files
        size_t pos = line.find(delimeter);
        return (toInt(line.substr(0, (int)pos)) + 1);
    }

    void writeInFile(std::string path, const std::vector<std::string>& v, bool app) {
        auto status = std::ios::out | std::ios::in | std::ios::app;

        if (!app)
            status = std::ios::out | std::ios::in | std::ios::trunc;

        std::ofstream fout(path, status);
        if (fout.fail())
            std::cout << "the file " << path << " can't open" << "\n";

        for (auto line : v) {
            if (line.length() == 0)
                continue;
            fout << line << "\n";
        }
        fout.close();
    }

    Question* getQuestion(int id, const std::map<Question*, std::vector<Question*>>& questions) {
        for (auto& p : questions) {
            if (p.first->getId() == id) return p.first;
            for (auto* e : p.second)
                if (e->getId() == id) return e;
        }
        return nullptr;
    }

} // namespace Utils

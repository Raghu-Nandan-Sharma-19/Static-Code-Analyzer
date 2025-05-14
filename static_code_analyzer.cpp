#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void analyzeCode(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    int lineNumber = 0;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << "\n";
        return;
    }

    while (getline(file, line)) {
        lineNumber++;

        if (line.length() > 80)
            std::cout << "Line " << lineNumber << ": Line exceeds 80 characters.\n";

        if (line.find("goto") != std::string::npos)
            std::cout << "Line " << lineNumber << ": Use of 'goto' is discouraged.\n";

        if (!line.empty() && line.back() != ';' && line.find("{") == std::string::npos &&
            line.find("}") == std::string::npos && line.find("#") == std::string::npos)
            std::cout << "Line " << lineNumber << ": Missing semicolon.\n";
    }

    file.close();
}

int main() {
    std::string filename;
    std::cout << "Enter the path to the C++ file to analyze: ";
    std::cin >> filename;
    analyzeCode(filename);
    return 0;
}

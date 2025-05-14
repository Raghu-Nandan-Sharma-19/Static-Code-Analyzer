#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

struct Issue {
    int lineNumber;
    std::string message;
};

void analyzeCode(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "❌ Error: Cannot open file: " << filename << "\n";
        return;
    }

    std::string line;
    int lineNumber = 0;
    std::regex semicolonRegex(".*[^;\\{\\}\\s]$");

    std::vector<Issue> issues;

    std::cout << "\n🔍 Starting static analysis of: " << filename << "\n";

    while (std::getline(file, line)) {
        lineNumber++;

        if (line.length() > 80) {
            issues.push_back({lineNumber, "⚠️ Line exceeds 80 characters"});
        }

        if (line.find("goto") != std::string::npos) {
            issues.push_back({lineNumber, "❗ Usage of 'goto' is discouraged"});
        }

        if (!line.empty() &&
            std::regex_match(line, semicolonRegex) &&
            line.find("#") != 0 &&
            line.find("for") == std::string::npos &&
            line.find("if") == std::string::npos &&
            line.find("while") == std::string::npos &&
            line.find("else") == std::string::npos &&
            line.find("switch") == std::string::npos) {
            issues.push_back({lineNumber, "⚠️ Might be missing a semicolon"});
        }
    }

    file.close();

    std::cout << "\n📋 Analysis Report\n";
    std::cout << "----------------------\n";

    if (issues.empty()) {
        std::cout << "✅ No issues found. Code looks clean!\n";
    } else {
        for (const auto& issue : issues) {
            std::cout << "Line " << issue.lineNumber << ": " << issue.message << "\n";
        }

        std::cout << "\nSummary: " << issues.size() << " issue(s) found.\n";
    }

    std::cout << "----------------------\n";
    std::cout << "✅ Static analysis complete.\n";
}

int main() {
    std::string  filename;
    std::cout << "Enter path to the C++ file to analyze: ";
    std::getline(std::cin, filename);

    analyzeCode(filename);
    return 0;
}

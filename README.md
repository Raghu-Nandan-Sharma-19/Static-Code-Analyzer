# Static Code Analyzer (C++)
This is a simple Static Code Analyzer written in C++ that performs basic code quality checks on .cpp files.

# 🔍 Features
Detects lines that exceed 80 characters

Flags usage of goto statements (considered bad practice)

Warns about lines that might be missing a semicolon

# 📁 Files
static_code_analyzer.cpp: Main source file of the analyzer

# 🧑‍💻 How to Use
1. Save the Source File
Save the C++ code into a file named:

Copy
Edit
static_code_analyzer.cpp

# 2. Compile the Code
Using g++ (GCC compiler), compile the program:

bash
Copy
Edit
g++ static_code_analyzer.cpp -o analyzer
3. Run the Analyzer
Execute the analyzer and input the path to the file you want to analyze:

bash
Copy
Edit
./analyzer
Then enter the path to the .cpp file when prompted.

# ✅ Example Output
pgsql
Copy
Edit
Enter the path to the C++ file to analyze: example.cpp
Line 4: Line exceeds 80 characters.
Line 12: Use of 'goto' is discouraged.
Line 17: Missing semicolon.

# 🚀 Purpose
This project simulates a part of the validation and quality-checking process involved in AI code generation workflows. It's especially helpful for junior developers to understand static analysis and code health checks.

# 📄 License
MIT License – feel free to use and modify.


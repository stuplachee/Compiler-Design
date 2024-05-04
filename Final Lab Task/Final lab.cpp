#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

string valid_keywords[] = {"int", "float", "double", "bool", "void", "char", "if", "else", "for", "while", "do", "return", "switch", "case", "default", "main", "cout", "cin", "string", "include", "using", "namespace", "std"};

bool is_valid_keyword(string word) {
    for (string keyword : valid_keywords) {
        if (keyword == word) {
            return true;
        }
    }
    return false;
}

bool is_valid_identifier(string word) {
    if (isalpha(word[0]) || word[0] == '_') {
        for (int i = 1; i < word.length(); i++) {
            if (!isalnum(word[i]) && word[i] != '_') {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool is_valid_constant(string word) {
    if (word.empty()) {
        return false;
    }
    if (word[0] == '"' && word[word.length() - 1] == '"') {
        return true;
    }
    for (char c : word) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool is_valid_operator(string word) {
    string operators = "+-*/%=!><&|";
    for (char c : word) {
        if (operators.find(c) != string::npos) {
            return true;
        }
    }
    return false;
}

bool is_valid_punctuation(string word) {
    string punctuations = "(){}[],;:";
    for (char c : word) {
        if (punctuations.find(c) != string::npos) {
            return true;
        }
    }
    return false;
}

bool is_comment(string line) {
    regex commentPattern("//.*");
    return regex_match(line, commentPattern);
}

int main() {
    ifstream inputFile("lex_input.txt");
    string currentLine;
    int lineNumber = 1;

    while (getline(inputFile, currentLine)) {
        if (currentLine.empty()) {
            continue;
        }

        cout << lineNumber << "st line: "<< endl;

        if (lineNumber == 1 && currentLine == "#include <iostream>") {
            cout << "   It's a header file declaration" << endl;
        } else if (lineNumber == 2 && currentLine == "using namespace std;") {
            cout << "   It's a namespace declaration" << endl;
        } else if (is_comment(currentLine)) {
            cout << "   Comment" << endl;
        } else {
            istringstream lineStream(currentLine);
            string currentToken;

            while (lineStream >> currentToken) {
                string lastChar = currentToken.substr(currentToken.length() - 1);
                if (is_valid_punctuation(lastChar)) {
                    currentToken = currentToken.substr(0, currentToken.length() - 1);
                }

                if (!currentToken.empty()) {
                    if (is_valid_keyword(currentToken)) {
                        cout << "   Keyword: " << currentToken << endl;
                    } else if (is_valid_identifier(currentToken)) {
                        cout << "   Identifier: " << currentToken << endl;
                    } else if (is_valid_constant(currentToken)) {
                        cout << "   Constant: " << currentToken << endl;
                    } else if (is_valid_operator(currentToken)) {
                        cout << "   Operator: " << currentToken << endl;
                    } else if (currentToken[0] == '#') {
                        cout << "   Invalid identifier: Identifier can't start with a special char" << endl;
                    }
                }

                if (is_valid_punctuation(lastChar)) {
                    cout << "   Punctuation: " << lastChar << endl;
                }
            }
        }
        lineNumber++;
    }

    inputFile.close();

    return 0;
}

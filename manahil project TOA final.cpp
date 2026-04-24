#include <iostream>
#include <cctype>
#include <string>
using namespace std;

// Keyword check
bool isKeyword(string word) {
    string keywords[] = {"int", "float", "if", "else", "while", "return"};
    for (int i=0; i<6; i++) 
        if (word == keywords[i]) return true;
    return false;
}

// Number check
bool isNumber(string word) {
    for (int i=0; i<word.length(); i++)
        if (!isdigit(word[i])) return false;
    return true;
}

// Identifier check
bool isIdentifier(string word) {
    if (!isalpha(word[0]) && word[0] != '_') return false;
    for (int i=0; i<word.length(); i++)
        if (!isalnum(word[i]) && word[i] != '_') return false;
    return true;
}

// Tokenize function
void tokenize(string code) {
    string word = "";
    for (int i=0; i<code.length(); i++) {
        char ch = code[i];
        if (isspace(ch) || ch=='(' || ch==')' || ch==';' || ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='=' || ch=='<' || ch=='>') {
            if (word != "") {
                if (isKeyword(word)) cout << word << " -> Keyword\n";
                else if (isNumber(word)) cout << word << " -> Number\n";
                else if (isIdentifier(word)) cout << word << " -> Identifier\n";
                else cout << word << " -> Unknown\n";
                word = "";
            }
            if (ch=='(' || ch==')' || ch==';' || ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='=' || ch=='<' || ch=='>')
                cout << ch << " -> Operator/Delimiter\n";
        } else word += ch;
    }
    if (word != "") {
        if (isKeyword(word)) cout << word << " -> Keyword\n";
        else if (isNumber(word)) cout << word << " -> Number\n";
        else if (isIdentifier(word)) cout << word << " -> Identifier\n";
        else cout << word << " -> Unknown\n";
    }
}

// Convert to lowercase (Dev C++ safe)
string toLowercase(string s) {
    for (int i=0; i<s.length(); i++)
        s[i] = tolower(s[i]);
    return s;
}

int main() {
    cout << "============================================\n";
    cout << "Project: Mini Lexical Analyzer (Mini-Lex)\n";
    cout << "Description: Tokenizes input source code line by line.\n";
    cout << "Course: 3rd Semester (SELF), Theory of Automata\n";
    cout << "Author: Chaudhary Manahil Rehman\n";
    cout << "============================================\n\n";

    cout << "Enter source code:\n";

    string line;
    while (true) {
        getline(cin, line);
        if (toLowercase(line) == "end") break;
        tokenize(line);
    }

    cout << "\n--- Tokenization Complete ---\n";

    // Wait for user to press Enter before closing (Dev C++ safe)
    cout << "Press Enter to exit...";
    cin.ignore(1000, '\n'); // ignore leftover input
    cin.get();              // wait for Enter

    return 0;
}

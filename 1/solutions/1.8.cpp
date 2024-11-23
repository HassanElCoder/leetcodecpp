#include <iostream>
#include <stack>
#include <string>

class BracketChecker {
public:
    // Check if the brackets in the expression are balanced.
    bool isBalanced(const std::string& expression) {
        std::stack<char> bracketStack;

        for (char ch : expression) {
            switch (ch) {
                case '(':
                case '[':
                case '{':
                    bracketStack.push(ch);
                    break;
                case ')':
                    if (bracketStack.empty() || bracketStack.top() != '(') return false;
                    bracketStack.pop();
                    break;
                case ']':
                    if (bracketStack.empty() || bracketStack.top() != '[') return false;
                    bracketStack.pop();
                    break;
                case '}':
                    if (bracketStack.empty() || bracketStack.top() != '{') return false;
                    bracketStack.pop();
                    break;
            }
        }

        return bracketStack.empty(); // If stack is empty, brackets are balanced.
    }
};

int main() {
    BracketChecker checker;

    // Test cases
    std::string expressions[] = {
        "{[()]}",      // Balanced
        "{[(])}",     // Not balanced
        "()",         // Balanced
        "([{}])",     // Balanced
        "({[)]}",     // Not balanced
        "",           // Balanced (empty string)
        "([]{})",     // Balanced
        "([)]",       // Not balanced
        "((()))",     // Balanced
        "([{])",      // Not balanced
        "{[()()]}",   // Balanced
        "{[}]",       // Not balanced
        "([{}])[]()", // Balanced
        "([)]{}",     // Not balanced
        "([{}])[]()", // Balanced
        "([{])[]()",  // Not balanced
        "([{}])[]()", // Balanced
        "([{}])[]()", // Balanced
        "([{}])[]()", // Balanced
        "([{}])[]()"  // Balanced
    };

    for (const std::string& expr : expressions) {
        if (checker.isBalanced(expr)) {
            std::cout << "The expression \"" << expr << "\" has balanced brackets." << std::endl;
        } else {
            std::cout << "The expression \"" << expr << "\" does not have balanced brackets." << std::endl;
        }
    }

    return 0;
}
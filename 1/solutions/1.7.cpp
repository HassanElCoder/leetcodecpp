#include <iostream>
#include <string>

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0') {
            return *s == '\0';
        }

        bool first_match = (*s != '\0') && ((*p == *s) || (*p == '.'));

        if (*(p + 1) == '*') {
            // p[1] is '*', so we have two choices:
            // 1. Use '*' to match zero characters: isMatch(s, p + 2)
            // 2. Use '*' to match one or more characters: first_match && isMatch(s + 1, p)
            return (isMatch(s, p + 2) || (first_match && isMatch(s + 1, p)));
        } else {
            // No '*', just match the current character and move to the next
            return first_match && isMatch(s + 1, p + 1);
        }
    }
};

int main() {
    Solution solution;

    // Test cases
    std::cout << std::boolalpha; // Print bool values as true/false
    std::cout << "isMatch(\"aa\", \"a\") -> " << solution.isMatch("aa", "a") << std::endl; // false
    std::cout << "isMatch(\"aa\", \"aa\") -> " << solution.isMatch("aa", "aa") << std::endl; // true
    std::cout << "isMatch(\"aaa\", \"aa\") -> " << solution.isMatch("aaa", "aa") << std::endl; // false
    std::cout << "isMatch(\"aa\", \"a*\") -> " << solution.isMatch("aa", "a*") << std::endl; // true
    std::cout << "isMatch(\"aa\", \".*\") -> " << solution.isMatch("aa", ".*") << std::endl; // true
    std::cout << "isMatch(\"acccccc\", \".*\") -> " << solution.isMatch("acccccc", ".*") << std::endl; // true
    

    return 0;
}
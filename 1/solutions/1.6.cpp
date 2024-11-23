#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;

    while (left < right) {
        // Move left pointer to the next alphanumeric character
        while (left < right && !isalnum(s[left])) {
            left++;
        }

        // Move right pointer to the previous alphanumeric character
        while (left < right && !isalnum(s[right])) {
            right--;
        }

        // Compare characters after converting to lowercase
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main() {
    string test1 = "A man, a plan, a canal: Panama";
    string test2 = "race a car";

    cout << (isPalindrome(test1) ? "true" : "false") << endl; 
    cout << (isPalindrome(test2) ? "true" : "false") << endl; 

    return 0;
}


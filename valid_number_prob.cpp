#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // Function to check if a given string is a valid number.
    bool isNumber(string s) {
        return is_valid_number(s);
    }

    // Function to validate if a string is a valid number.
    bool is_valid_number(const std::string& s) {
        if (s.empty()) return false; // An empty string is not a valid number.

        size_t i = 0;
        if (s[i] == '+' || s[i] == '-') i++; // Handle an optional sign.

        bool has_integer_part = false;
        while (i < s.size() && isdigit(s[i])) {
            has_integer_part = true; // Mark that we've encountered an integer part.
            i++;
        }

        bool has_decimal_part = false;
        if (i < s.size() && s[i] == '.') {
            i++;
            while (i < s.size() && isdigit(s[i])) {
                has_decimal_part = true; // Mark that we've encountered a decimal part.
                i++;
            }
        }

        if (i < s.size() && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            if (i < s.size() && (s[i] == '+' || s[i] == '-')) i++; // Handle an optional sign for the exponent.
            if (i == s.size() || !isdigit(s[i])) {
                return false; // Exponent must be followed by at least one digit.
            }
            while (i < s.size() && isdigit(s[i])) {
                i++;
            }
        }
        return i == s.size() && (has_integer_part || has_decimal_part);
        // The number is valid if we've consumed the entire string, and there's at least an integer part or a decimal part.
    }
};

int main() {
    Solution solution;

    string userInput;
    cout << "Enter a string to check if it's a valid number: ";
    cin >> userInput;

    bool isValid = solution.isNumber(userInput);
    
    if (isValid) {
        cout << "The input is a valid number." << endl;
    } else {
        cout << "The input is not a valid number." << endl;
    }

    return 0;
}

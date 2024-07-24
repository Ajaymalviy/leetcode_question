#include <vector>
#include <string>

class Solution {
public:
    // Function to generate all possible letter combinations for a given string of digits
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        
        // Check if the input string is empty
        if (digits.empty()) {
            return result;
        }

        // Mapping of digits to corresponding letters
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        // Start the backtracking process
        backtrack(result, "", digits, 0, mapping);

        // Return the final result
        return result;
    }

private:
    // Backtracking function to explore all possible combinations
    void backtrack(vector<string>& result, string current, const string& digits, int index, const vector<string>& mapping) {
        // If we have reached the end of the input digits, add the current combination to the result
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        

        // Get the current digit and its corresponding letters
        int digit = digits[index] - '0';
        string letters = mapping[digit];

        // Iterate over each letter and explore further possibilities
        for (char letter : letters) {
            backtrack(result, current + letter, digits, index + 1, mapping);
        }
    }
};

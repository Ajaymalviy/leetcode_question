#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentList;
        backtrack(result, s, 0, currentList);
        return result;
    }

private:
    void backtrack(vector<vector<string>>& result, string& s, int start, vector<string>& currentList) {
        if (start >= s.length()) {
            result.push_back(currentList);
            return;
        }
        
        for (int end = start; end < s.length(); ++end) {
            if (isPalindrome(s, start, end)) {
                currentList.push_back(s.substr(start, end - start + 1));
                backtrack(result, s, end + 1, currentList);
                currentList.pop_back(); // Backtrack
            }
        }
    }
    
    bool isPalindrome(string& s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
};

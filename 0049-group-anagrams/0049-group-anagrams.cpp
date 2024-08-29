#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Create a hashmap to store groups of anagrams
        unordered_map<string, vector<string>> anagramGroups;
        
        // Iterate through each string in the input array
        for (const string& str : strs) {
            // Sort the characters of the string
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            
            // Add the string to its corresponding group in the hashmap
            anagramGroups[sortedStr].push_back(str);
        }


        
        // Convert the hashmap values to a vector of vectors
        vector<vector<string>> result;
        for (const auto& pair : anagramGroups) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};

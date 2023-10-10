#include<iostream.h>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        // Create a hashmap to count the occurrences of each digit in the secret
        unordered_map<char, int> m;
        
        // Initialize the number of bulls to 0
        int bulls = 0;
        
        // Iterate through the secret and count the bulls
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            }
        }
        
        // Initialize a variable to count the cows
        int count = 0;
        
        // Iterate through the guess
        for (int i = 0; i < guess.size(); i++) {
            // If the digit in guess exists in the secret and is not used up (counted as a bull)
            if (m[guess[i]] > 0) {
                count++;
                m[guess[i]]--; // Reduce the count in the hashmap
            } else {
                // If the digit in guess is not in the secret or is already counted as a cow
                m[secret[i]]++; // Increase the count in the hashmap
            }
        }
        
        // Calculate the number of cows as the total matches minus bulls
        int cows = secret.size() - bulls - count;
        
        // Construct the result string in the format "xAyB" and return it
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};

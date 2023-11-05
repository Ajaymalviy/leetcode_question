class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();         // Get the size of the input array.
        int max_element = arr[0];   // Initialize the maximum element as the first element.
        int consecutive_wins = 0;   // Initialize the count of consecutive wins.

        for (int i = 1; i < n; i++) { // Iterate through the array starting from the second element.
            if (arr[i] > max_element) {  // Compare the current element with the maximum element.
                max_element = arr[i];   // If the current element is greater, update the maximum element.
                consecutive_wins = 1;   // Reset the count of consecutive wins to 1.
            } else {
                consecutive_wins++;     // If the current element is smaller, increment the count of consecutive wins.
            }

            if (consecutive_wins == k) { // If the maximum element has won k consecutive rounds, return it as the winner.
                return max_element;
            }

            if (consecutive_wins == 1) {
                // Swap the elements to maintain the game rule. The current maximum element moves to the front.
                swap(arr[0], arr[i]);
            }
        }

        // If we reach this point, the maximum element is the winner because it has won the most rounds.
        return max_element;
    }
};

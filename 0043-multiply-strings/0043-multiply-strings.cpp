class Solution {
public:
  string multiply(string num1, string num2) {
    // Create a result string initialized with '0's.
    string s(num1.length() + num2.length(), '0');

    // Perform long multiplication using nested loops.
    for (int i = num1.length() - 1; i >= 0; --i)
      for (int j = num2.length() - 1; j >= 0; --j) {
        // Calculate the product of the current digits.
        const int mult = (num1[i] - '0') * (num2[j] - '0');
        
        // Calculate the sum of the product and the current digit in the result.
        const int sum = mult + (s[i + j + 1] - '0');
        
        // Handle carry by adding it to the digit at position (i + j).
        s[i + j] += sum / 10;
        
        // Set the current digit in position (i + j + 1).
        s[i + j + 1] = '0' + sum % 10;
      }

    // Find the index of the first non-zero digit in the result.
    const int i = s.find_first_not_of('0');

    // If there are no non-zero digits, return "0"; otherwise, return the substring from the first non-zero digit.
    return i == -1 ? "0" : s.substr(i);
  }
};

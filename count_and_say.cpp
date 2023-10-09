// Initialize an array to store intermediate results
string m[31] = {""};

class Solution {
public:
    string countAndSay(int n) {
        // Base case: The first term is "1"
        m[1] = "1";
        string next, prev;
        int i, j, len;

        // Generate the say(i)
        for (i = 2; i < n + 1; i++) {
            if (m[i] != "")
                continue;
            next = "";
            prev = m[i - 1];
            len = prev.size();
            int count = 1;

            // Read out the say(i-1) i.e., string prev
            for (j = 1; j < len; j++) {
                if (prev[j - 1] == prev[j])
                    count++;
                else {
                    next = next + to_string(count) + prev[j - 1];
                    count = 1;
                }
            }
            next = next + to_string(count) + prev[j - 1];
            m[i] = next;
        }
        return m[n]; // Return the nth term of the sequence
    }
};

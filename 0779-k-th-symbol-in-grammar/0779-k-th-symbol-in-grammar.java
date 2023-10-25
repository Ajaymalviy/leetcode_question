class Solution {
    public int kthGrammar(int n, int k) {
        // Base case: If n is 1, there is only one row, which is '0'.
        if (n == 1) {
            return 0;
        }
        
        // Calculate the length of the nth row without generating the entire row.
        int lenN = 1 << (n - 1);
        
        // If k is in the first half of the nth row, it has the same value as k in the (n-1)th row.
        if (k <= lenN / 2) {
            return kthGrammar(n - 1, k);
        }
        
        // If k is in the second half, it's the opposite of the k in the (n-1)th row.
        return 1 - kthGrammar(n - 1, k - lenN / 2);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int n = 3;
        int k = 3;
        int result = solution.kthGrammar(n, k);
        System.out.println(result);  // Output: 1
    }
}




 
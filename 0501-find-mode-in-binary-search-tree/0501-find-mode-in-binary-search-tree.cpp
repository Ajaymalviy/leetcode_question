/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        int maxCount = 0;  // Maximum frequency of any element
        int currentCount = 0;  // Frequency of the current element
        TreeNode* prev = nullptr;  // Pointer to the previous node during in-order traversal

        // Helper function for in-order traversal
        function<void(TreeNode*)> inOrder = [&](TreeNode* node) {
            if (node == nullptr) return;

            inOrder(node->left);

            if (prev != nullptr && prev->val == node->val) {
                currentCount++;
            } else {
                currentCount = 1;
            }

            if (currentCount == maxCount) {
                result.push_back(node->val);
            } else if (currentCount > maxCount) {
                result.clear();
                result.push_back(node->val);
                maxCount = currentCount;
            }

            prev = node;
            inOrder(node->right);
        };

        inOrder(root);

        return result;
    }
};

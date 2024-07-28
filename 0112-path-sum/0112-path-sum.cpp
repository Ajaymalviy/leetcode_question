#include <iostream>

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: if the current node is null, return false
        if (root == nullptr) {
            return false;
        }

        // If the current node is a leaf and its value equals the remaining target sum,
        // then a path with the target sum is found.
        if (root->left == nullptr && root->right == nullptr && root->val == targetSum) {
            return true;
        }

        
        // Recursively check for the target sum in the left and right subtrees
        // by subtracting the current node's value from the target sum.
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};



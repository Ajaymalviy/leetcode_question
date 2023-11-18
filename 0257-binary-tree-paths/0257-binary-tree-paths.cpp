#include <vector>
#include <string>
#include <sstream>  // For stringstream

using namespace std;

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root != nullptr) {
            traverse(root, "", result);
        }
        return result;
    }

private:
    void traverse(TreeNode* node, string path, vector<string>& result) {
        if (node == nullptr) {
            return;
        }

        // Append the current node's value to the path
        path += to_string(node->val);

        // Check if the current node is a leaf node
        if (node->left == nullptr && node->right == nullptr) {
            result.push_back(path);  // Add the path to the result
        } else {
            path += "->";  // Add "->" to separate node values in the path
            traverse(node->left, path, result);   // Recursively traverse the left subtree
            traverse(node->right, path, result);  // Recursively traverse the right subtree
        }
    }
};

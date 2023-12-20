
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true; // An empty tree is balanced
        }

        // Check if the left and right subtrees are balanced
        bool leftBalanced = isBalanced(root->left);
        bool rightBalanced = isBalanced(root->right);

        // Check if the current subtree is balanced
        bool currentBalanced = abs(height(root->left) - height(root->right)) <= 1;

        // Return true only if both subtrees and the current subtree are balanced
        return leftBalanced && rightBalanced && currentBalanced;
    }

private:
    int height(TreeNode* node) {
        if (node == nullptr) {
            return 0; // Height of an empty subtree is 0
        }

        // Calculate the height recursively
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // Height of the current node's subtree is 1 + maximum height of left and right subtrees
        return 1 + std::max(leftHeight, rightHeight);
    }
};

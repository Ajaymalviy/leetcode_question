class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        def dfs(node, current_sum):
            if not node:
                return 0
            
            # Update the current number formed by the path from root to the current node
            current_sum = current_sum * 10 + node.val
            
            # If the current node is a leaf, return the current number
            if not node.left and not node.right:
                return current_sum
            
            # Recursively calculate the sum for left and right subtrees
            left_sum = dfs(node.left, current_sum)
            right_sum = dfs(node.right, current_sum)
            
            # Return the sum of left and right subtree sums
            return left_sum + right_sum
        
        # Start the depth-first traversal from the root with current sum as 0
        return dfs(root, 0)

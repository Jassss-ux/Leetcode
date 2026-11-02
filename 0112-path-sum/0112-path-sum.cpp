class Solution {
public:
    bool checkPathSum(TreeNode* root, int targetSum, int currentSum) {
        if (root == NULL) {
            return false;
        }

        currentSum += root->val;

        // Check only at leaf nodes
        if (root->left == NULL && root->right == NULL) {
            return currentSum == targetSum;
        }

        return checkPathSum(root->left, targetSum, currentSum) ||
               checkPathSum(root->right, targetSum, currentSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return checkPathSum(root, targetSum, 0);
    }
};
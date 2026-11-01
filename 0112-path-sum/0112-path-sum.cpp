/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool find(TreeNode* root, int targetSum, int sum) {

        if (root == NULL) {
            return false;
        }
        sum = sum + root->val;

        if (root->left == NULL && root->right == NULL) {
            return sum == targetSum;
        }
        return find(root->left, targetSum, sum) ||
               find(root->right, targetSum, sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        if (root == NULL) {
            return false;
        }
        return find(root, targetSum, sum);
    }
};
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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // If either of the nodes is NULL,
        // then both should be NULL for the trees to be same.
        // p == q will return:
        // true  -> if both are NULL
        // false -> if only one is NULL
        if (p == NULL || q == NULL) {
            return p == q;
        }

        // Recursively check whether the left subtrees are same
        bool leftsubstreesame = isSameTree(p->left, q->left);

        // Recursively check whether the right subtrees are same
        bool rightsubstreesame = isSameTree(p->right, q->right);

        // For two trees to be same:
        // 1. Left subtrees must be same
        // 2. Right subtrees must be same
        // 3. Current node values must be same
        return leftsubstreesame && rightsubstreesame && (p->val == q->val);
    }
};
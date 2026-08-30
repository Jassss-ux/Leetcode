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

    // This function checks whether two trees are exactly identical.
    // Same structure + same values at every node.
    bool identical(TreeNode* p, TreeNode* q) {

        // If both nodes are NULL, they are identical.
        // If only one is NULL, they are not identical.
        if (p== NULL || q == NULL) {
            return p== q;
        }

        // Check whether the left subtrees are identical.
        bool substreeeinleft = identical(p->left, q->left);

        // Check whether the right subtrees are identical.
        bool substreeeinright = identical(p->right, q->right);

        // Trees are identical only if:
        // 1. Current node values are same
        // 2. Left subtrees are identical
        // 3. Right subtrees are identical
        return substreeeinleft && substreeeinright &&
               (p->val == q->val);
    }


    // Checks whether subRoot exists as a subtree inside root.
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // If root becomes NULL:
        // - If subRoot is also NULL -> both are empty, so true.
        // - Otherwise -> subtree cannot be found.
        if (root == NULL || subRoot == NULL) {
            return root == subRoot;
        }

        // If current root node has the same value as subRoot's root,
        // check whether the complete trees starting from these nodes
        // are identical.
        if (root->val == subRoot->val && identical(root, subRoot)) {
            return true;
        }

        // If current node is not the starting point of subRoot,
        // search for subRoot in the left or right subtree.
        //
        // '||' means if we find the subtree on either side,
        // the answer will be true.
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
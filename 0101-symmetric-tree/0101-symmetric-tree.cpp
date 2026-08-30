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

    // Ye function check karega ki p aur q
    // ek dusre ke mirror hain ya nahi
    bool check(TreeNode* p, TreeNode* q) {

        // Agar p ya q mein se koi ek NULL hai,
        // toh dono NULL hone chahiye tabhi mirror honge
        //
        // p == q:
        // Dono NULL  -> true
        // Ek NULL     -> false
        if(p == NULL || q == NULL) {
            return p == q;
        }

        // Mirror nodes ki values same honi chahiye
        // Agar values different hain toh symmetric nahi hai
        if(p->val != q->val) {
            return false;
        }

        // p ka LEFT subtree
        // q ke RIGHT subtree ka mirror hona chahiye
        bool leftmirror = check(p->left, q->right);

        // p ka RIGHT subtree
        // q ke LEFT subtree ka mirror hona chahiye
        bool rightmirror = check(p->right, q->left);

        // Dono conditions true honi chahiye:
        // 1. Left of p == Right of q
        // 2. Right of p == Left of q
        return leftmirror && rightmirror;
    }

    bool isSymmetric(TreeNode* root) {

        // Agar tree empty hai,
        // toh obviously symmetric hai
        if(root == NULL) {
            return true;
        }

        // Root ke left aur right subtree ko
        // mirror ke form mein compare karenge
        return check(root->left, root->right);
    }
};
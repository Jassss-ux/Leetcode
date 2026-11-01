class Solution {
public:
    vector<vector<int>> final;

    vector<vector<int>> find(TreeNode* root, int targetSum,
                             int sum, vector<int>& ans) {

        // Agar current node NULL hai, toh aage traverse nahi kar sakte
        if (root == NULL) {
            return final;
        }

        // Current node ki value ko path ke sum mein add karo
        sum = sum + root->val;

        // Current node ko path mein add karo
        ans.push_back(root->val);

        // Check karo ki current node leaf node hai ya nahi
        if (root->left == NULL && root->right == NULL) {

            // Agar leaf tak ka sum targetSum ke equal hai
            if (sum == targetSum) {

                // Current valid path ko final answer mein store karo
                final.push_back(ans);
            }
        }

        // Agar left child exist karta hai, toh left subtree mein jao
        if (root->left) {
            find(root->left, targetSum, sum, ans);
        }

        // Agar right child exist karta hai, toh right subtree mein jao
        if (root->right) {
            find(root->right, targetSum, sum, ans);
        }

        // Backtracking:
        // Current node se explore karna complete ho gaya hai,
        // isliye uski value ko current path se remove karo
        ans.pop_back();

        return final;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        // Agar tree empty hai, toh empty answer return karo
        if (root == NULL) {
            return final;
        }

        // Ek path store karne ke liye vector
        vector<int> ans;

        // Starting mein path sum zero hoga
        int sum = 0;

        // Root se traversal start karo
        find(root, targetSum, sum, ans);

        // Saare valid root-to-leaf paths return karo
        return final;
    }
};
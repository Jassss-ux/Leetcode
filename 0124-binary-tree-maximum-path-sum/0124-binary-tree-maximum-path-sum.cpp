class Solution {
public:
    int maximum = INT_MIN;

    int check(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftsum = max(0,check(root->left));
        int rightsum = max(0,check(root->right));

        // Maximum path through current node
        maximum = max(maximum,
                      leftsum + rightsum + root->val);

        // Parent ko ek hi side ka path return karna hai
        return root->val + max(leftsum, rightsum);
    }

    int maxPathSum(TreeNode* root) {
        check(root);
        return maximum;
    }
};
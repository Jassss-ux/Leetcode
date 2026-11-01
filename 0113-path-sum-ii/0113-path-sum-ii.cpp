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
    vector<vector<int>>final;
    vector<vector<int>> find(TreeNode* root, int targetSum , int sum , vector<int>&ans){
        if(root==NULL){
            return final;
        }
        
        sum = sum + root->val;
        ans.push_back(root->val);
        if(root->left == NULL && root->right ==NULL){
            if(sum == targetSum){
                final.push_back(ans);
            }
        }

        if(root->left){
            find(root->left, targetSum, sum, ans);
        }

        if(root->right){
            find(root->right,targetSum, sum , ans);
        }

        ans.pop_back();
        return final;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return final;
        }
        vector<int>ans;
        int sum =0;

        find(root,targetSum,sum, ans);
        return final;
        
    }
};
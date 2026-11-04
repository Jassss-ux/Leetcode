/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* search(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(original ==  NULL || cloned ==NULL){
            return NULL;
        }

        if(original == target){
            return cloned;
        }

        TreeNode* left = search(original->left,cloned->left,target);
        TreeNode* right = search(original->right,cloned->right,target);


        if(left ==NULL){
            return right;
        }
        
        else{
            return left;
        }


    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return search(original, cloned, target);


        
    }
};
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
    void invert(TreeNode* root){
        if(root ==NULL){
            return;
        }
        //swap krdiya humne left and right childdd using the swap fucntion of c++ and recursive call dedei left and right part ke liye

        swap(root->left,root->right);
        
        invert(root->left);
        invert(root->right);
        

    }
    TreeNode* invertTree(TreeNode* root) {
            invert(root); //yeh hamre new tree banadega and us new inverted tree ka root dedega
            return root;//and voh new root jo hai inverted tree ka voh ye hoga isko hi return krdo

            
    }
};
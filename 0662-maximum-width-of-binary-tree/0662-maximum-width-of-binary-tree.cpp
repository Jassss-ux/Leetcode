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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        int ans =0;
        while(!q.empty()){
             unsigned long long  miniumindexofthatlevel = q.front().second;
            int size = q.size();
            unsigned long long first , last; //this will calculate the widhth by using the formulas last -frist +1  this first and last will be the indexs
            for(  int i =0; i<size;i++){ //this for LOOP will calcute the index values for every nodes 
                unsigned long long currentindex = q.front().second -  miniumindexofthatlevel; //this is to prevent that overflow condition 
                //index - min of that level wala conceptt 
                TreeNode* currentnode = q.front().first; //us level ki no node hogi voh hamri current node mein store karwali hai 
                q.pop();
                if(i==0){
                    first = currentindex;
                }
                if(i == size-1){
                    last = currentindex;
                }
                //idhr hum currentnode use krhe hai kyuki hummee jis node par abhi hai us node ke hisab se aage indexing krni hai 
                if(currentnode->left){ 
                    q.push({currentnode->left, currentindex*2+1});
                }
                if(currentnode->right){
                    q.push({currentnode->right,currentindex*2+2});
                }
            }
            ans = max(ans,(int)(last-first+1));
        }
        return ans;

    }
};
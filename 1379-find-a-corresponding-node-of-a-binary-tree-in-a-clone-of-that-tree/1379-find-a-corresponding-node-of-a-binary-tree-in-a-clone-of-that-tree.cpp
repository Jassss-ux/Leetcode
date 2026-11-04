
class Solution {
public:
    TreeNode* search(TreeNode* original, TreeNode* cloned, TreeNode* target){

        // Agar koi bhi tree NULL hai toh NULL return kar do
        if(original == NULL || cloned == NULL){
            return NULL;
        }

        // Check karo ki current original node hi target hai ya nahi
        // Agar target mil gaya toh uska corresponding cloned node return karo
        if(original == target){
            return cloned;
        }

        // Dono trees ke left subtree mein target search karo
        TreeNode* left = search(original->left, cloned->left, target);

        // Dono trees ke right subtree mein target search karo
        TreeNode* right = search(original->right, cloned->right, target);

        // Agar left subtree mein target nahi mila
        // Toh right subtree ka result return kar do
        if(left == NULL){
            return right;
        }

        // Agar left mein target mil gaya toh left ka result return karo
        else{
            return left;
        }
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

        // Search function call karke corresponding cloned node return karo
        return search(original, cloned, target);
    }
};

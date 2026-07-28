/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom  =  m-1;
        vector<vector<int>>ans(m, vector<int>(n,-1)); //ans vector ko size diya hai m x n ka and -1 dala hai pura matrix mein start mein jese hi hum sari values dalte jynge array ke andr head ki -1 repalce hojyga and jab head ki values khtm hogyi uske badh -1 rhega matrix ho humne chaiye ans mein
        while( left <= right && top <= bottom){
            // left se right move 
            for( int i = left ; i<= right &&  head != NULL; i++){
                ans[top][i]= head->val; 
                head = head->next;
            }
            top++;

            // top to bottom
            for( int i = top ; i<=bottom && head != NULL; i++){
                ans[i][right] = head->val;
                head = head->next;
            }
            right--;

            //top row and right column ke badh matrix ki size check krna padhta hai so if(top<=bottom) ata hai right to left mein and if( left<= right)  ata hai bottom to top mein

            // right to left
            if( top<=bottom){
            for( int i = right ;i>=left  && head != NULL;i--){
                ans[bottom][i] = head->val;
                head = head->next;
            }
            bottom--;
            }

            //bottom to top
            if( left<= right){
            for( int i = bottom ; i>=top && head!= NULL;i--){
                ans[i][left] = head->val;
                head = head->next;
            }
            left ++;
            }
        }

        return ans;
        
    }
};
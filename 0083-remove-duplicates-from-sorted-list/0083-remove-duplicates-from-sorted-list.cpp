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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        while( temp != NULL && temp->next != NULL){
            if( temp->val == temp->next->val){  //temp variable banaya head se start hua temp ki abhi value ko compare kro uski next ki value ke sath agr match hogyi toh temp ke next ke next ki taraf point krdo 
                temp->next = temp->next->next;
            }
            else{
                temp = temp->next;  // agr nhi match khati toh temp ko normal upadte krdo next varible pe check krne ke liye
            }
        }
        return head;
        
    }
};
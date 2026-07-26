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
    void reorderList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return; 

        //find the middle of list step 1
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        //step 2 reverse the second half of the list
        ListNode* prev = NULL;
        ListNode* curr =slow->next;
        slow->next = NULL;  // slow mera mid hai mid ke next ko null krenge toh voh list seprate krdega iske badh huum second  hafl ko reverse kr skhte h aram se    
        ListNode* next =NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr =next;
        }
        
         // Step 3: Merge
        ListNode* first = head;
        ListNode* second = prev;

        while(second){

            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};
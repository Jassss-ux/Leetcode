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
    ListNode* removeElements(ListNode* head, int val) {

        // Dummy node banayi taaki agar head hi delete karna ho to bhi easily handle ho jaye.
        // Example:
        // head = [6,1,2], val = 6
        // Dummy -> 6 -> 1 -> 2
        ListNode* newnode = new ListNode(0);

        // Dummy node ko original head se connect kar diya.
        // Ab traversal dummy se start hoga.
        newnode->next = head;

        // Current pointer dummy se start karega.
        // Iska kaam current->next ko check karna hai.
        ListNode* current = newnode;

        // Jab tak current ke aage node exist karti hai.
        while (current->next != NULL) {

            // Agar next node ki value val ke equal hai,
            // to us node ko skip kar do.
            //
            // Example:
            // 1 -> 2 -> 6 -> 3
            //          ^
            //   current->next
            //
            // Skip karne ke baad:
            // 1 -> 2 -------> 3
            if (current->next->val == val) {
                current->next = current->next->next;
            }

            // Agar delete nahi karna,
            // to current ko aage badha do.
            else {
                current = current->next;
            }
        }

        // Dummy ke baad wali node hi actual head hogi.
        // Example:
        // Dummy -> 1 -> 2 -> 3
        // Return = 1
        return newnode->next;
    }
};
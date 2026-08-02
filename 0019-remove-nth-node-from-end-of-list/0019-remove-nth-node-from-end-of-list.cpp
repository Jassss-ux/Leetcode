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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;  //to prevserve head position to return the final linkedlist

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // fast ko n+1 steps aage le jao
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // dono pointers saath move karo
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // nth node delete
        slow->next = slow->next->next;

        return dummy->next;
    }
};
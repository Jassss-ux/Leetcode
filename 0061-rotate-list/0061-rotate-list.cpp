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
    ListNode* rotateRight(ListNode* head, int k) {

        int length = 1;
        ListNode* tail = head;

        // Edge Cases:
        // 1. Empty linked list
        // 2. Only one node present
        // 3. Rotation count is 0
        // In all these cases, the list remains unchanged.
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        // Find the length of the linked list
        // Also move the 'tail' pointer to the last node.
        while (tail->next != NULL) {
            length++;
            tail = tail->next;
        }

        // Example:
        // List = 1 -> 2 -> 3 -> 4 -> 5
        // Length = 5
        //
        // If k = 10
        // 10 % 5 = 0
        //
        // Rotating the list 5 times brings it back to its original form.
        // Rotating 10 times = Rotate 5 + Rotate 5
        // Hence, no changes in the list.
        if (k % length == 0) {
            return head;
        }

        // Reduce large values of k.
        //
        // Example:
        // Length = 5
        // k = 13
        //
        // 13 = 5 + 5 + 3
        //
        // Rotating 5 times gives the original list.
        // Again rotating another 5 times also gives the original list.
        // Therefore, only 3 rotations actually matter.
        //
        // k = 13 % 5 = 3
        k = k % length;

        // Convert the linked list into a circular linked list.
        //
        // Example:
        // 1 -> 2 -> 3 -> 4 -> 5
        // ^                   |
        // |___________________|
        tail->next = head;

        // Find the new tail.
        //
        // New Tail will be at (length - k - 1) index (0-based)  // in 1 based index new tail will be lenght - k 
        //
        // Example:
        // List = 1 -> 2 -> 3 -> 4 -> 5
        // Length = 5
        // k = 2
        //
        // New Tail = 3
        // New Head = 4
        //
        // Result:
        // 4 -> 5 -> 1 -> 2 -> 3
        ListNode* newTail = head;

        for (int i = 1; i < length - k; i++) {
            newTail = newTail->next;
        }

        // Node after newTail becomes the new head.
        ListNode* newHead = newTail->next;

        // Break the circular linked list.
        newTail->next = NULL;

        return newHead;
    }
};
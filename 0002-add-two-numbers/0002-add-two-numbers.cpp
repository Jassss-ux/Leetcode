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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy node answer linked list ko easily banane ke liye use kiya hai
        ListNode* dummy = new ListNode(0);

        int carry = 0;

        // Current pointer hamesha answer list ke last node par rahega
        ListNode* current = dummy;

        // Jab tak l1 ya l2 me nodes bache hain ya carry bacha hua hai, tab tak addition karte rahenge
        while (l1 != NULL || l2 != NULL || carry) {

            // Har iteration me sum ki starting carry se hogi,
            // kyuki pichli addition ka carry bhi current addition me add hota hai
            int sum = carry;

            // Agar l1 exist karti hai to uska value sum me add karo
            // aur l1 ko next node par move kar do
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Agar l2 exist karti hai to uska value bhi sum me add karo
            // aur l2 ko next node par move kar do
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Nayi carry calculate karo jo next iteration me use hogi
            carry = sum / 10;

            // Current digit (sum % 10) ko answer linked list me add kar do
            current->next = new ListNode(sum % 10);

            // Current pointer ko newly added node par move kar do
            current = current->next;
        }

        // Dummy ke baad se actual answer linked list start hoti hai
        return dummy->next;
    }
};
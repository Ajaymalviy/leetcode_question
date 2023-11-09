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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;

        // Count the number of nodes in the current group
        while (curr != nullptr && count < k) {
            curr = curr->next;
            count++;
        }

        // If the current group has k nodes, reverse it
        if (count == k) {
            // Reverse the next k nodes
            ListNode* reversedHead = reverseKGroup(curr, k);

            // Reverse the current k nodes
            ListNode* prev = nullptr;
            curr = head;
            for (int i = 0; i < k; i++) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // Connect the reversed nodes with the rest of the list
            head->next = reversedHead;

            // Return the new head of the reversed group
            return prev;
        }

        // If the current group has less than k nodes, return the head as is
        return head;
    }
};

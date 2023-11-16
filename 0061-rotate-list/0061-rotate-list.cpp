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
        if (!head || k == 0) {
            return head;
        }

        // Step 1: Find the length of the linked list
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            length++;
            tail = tail->next;
        }

        // Step 2: Calculate the effective rotation value
        int effectiveK = k % length;

        // Step 3: If no rotation is needed, return the original head
        if (effectiveK == 0) {
            return head;
        }

        // Step 4: Move to the node that will become the new head after rotation
        int stepsToNewHead = length - effectiveK - 1;
        ListNode* newHead = head;
        while (stepsToNewHead > 0) {
            newHead = newHead->next;
            stepsToNewHead--;
        }

        // Update pointers for rotation
        ListNode* newTail = newHead;
        newHead = newHead->next;
        newTail->next = nullptr;
        tail->next = head;

        return newHead;
    }
};

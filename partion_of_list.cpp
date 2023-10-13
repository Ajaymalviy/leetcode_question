/*
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
    ListNode* partition(ListNode* head, int x) {
        // Initialize two dummy nodes to help with partitioning.
        ListNode* small = new ListNode(-1);
        ListNode* large = new ListNode(-1);
        // Create pointers to the head of the small and large partitions.
        ListNode* small_head = small;
        ListNode* large_head = large;
        
        // Traverse the original list.
        while (head) {
            if (head->val < x) {
                // If the current node's value is less than x, add it to the 'small' partition.
                small->next = head;
                small = small->next;
                head = head->next;
                small->next = NULL; // Separate the added node from the rest of the 'small' partition.
            } else {
                // If the current node's value is greater or equal to x, add it to the 'large' partition.
                large->next = head;
                large = large->next;
                head = head->next;
                large->next = NULL; // Separate the added node from the rest of the 'large' partition.
            }
        }
        // Connect the 'small' partition to the 'large' partition.
        small->next = large_head->next;

        // Return the head of the sorted list.
        return small_head->next;
    }
};

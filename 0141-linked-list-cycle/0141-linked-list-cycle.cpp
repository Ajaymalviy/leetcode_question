/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            // If the list is empty or has only one node, there can't be a cycle
            return false;
        }
        
        ListNode *tortoise = head;
        ListNode *hare = head;
        
        while (hare && hare->next) {
            tortoise = tortoise->next;
            hare = hare->next->next;
            
            // If there is a cycle, the tortoise and hare will meet at some point
            if (tortoise == hare) {
                return true;
            }
        }
        
        // If the hare reaches the end of the list, there is no cycle
        return false;
    }
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        // Create a dummy node to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Initialize a hash map to store running sums and corresponding nodes
        unordered_map<int, ListNode*> sum_map;
        int prefix_sum = 0;
        ListNode* current = dummy;
        
        while (current) {
            prefix_sum += current->val;
            
            // If we find a node with a running sum seen before
            if (sum_map.find(prefix_sum) != sum_map.end()) {
                // Remove nodes between the two occurrences of the same running sum
                ListNode* prev = sum_map[prefix_sum]->next;
                int temp_sum = prefix_sum + prev->val;
                while (temp_sum != prefix_sum) {
                    sum_map.erase(temp_sum);
                    prev = prev->next;
                    temp_sum += prev->val;
                }
                sum_map[prefix_sum]->next = current->next;
            } else {
                // Store the current running sum and node in the hash map
                sum_map[prefix_sum] = current;
            }
            
            // Move to the next node
            current = current->next;
        }
        
        return dummy->next;
    }
};

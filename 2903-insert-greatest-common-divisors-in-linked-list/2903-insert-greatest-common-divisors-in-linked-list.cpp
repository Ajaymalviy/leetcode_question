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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        ListNode* current = head;
        ListNode* prev = nullptr;

        if(head == nullptr || head->next == nullptr) return head;

        while(current->next != nullptr){
            prev = current;
            current = current->next;
            int maxDivisor = greatestCommonDivisor(prev->val, current->val);

            ListNode* temp = current;

            ListNode* ans = new ListNode(maxDivisor);

            prev->next = ans;
            ans->next = temp;
        }

        return head;
    }

private:
    int greatestCommonDivisor(int a, int b) {

        int min = (a < b) ? a : b;

        int max = -1;

        for (int i = 1; i <= min; i++) {
            if (a % i == 0 && b % i == 0) {
                max = i;
            }
        }

        return max;
    }
};
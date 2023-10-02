

// Call the addTwoNumbers function with l1 and l2 as input
ListNode* result = Solution().addTwoNumbers(l1, l2);

// Define a structure for singly-linked list nodes
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Function to add two numbers represented by linked lists
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create temporary pointers for l1 and l2
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        // Initialize variables for the result
        ListNode* ans = nullptr; // Result linked list
        ListNode* head = nullptr; // Pointer to the head of the result
        int carry = 0; // Initialize the carry to 0

        while (temp1 != nullptr || temp2 != nullptr) {
            // Get the values at the current positions (if available)
            int val1 = (temp1 != nullptr) ? temp1->val : 0;
            int val2 = (temp2 != nullptr) ? temp2->val : 0;

            // Calculate the sum of values and carry from previous step
            int sum = val1 + val2 + carry;

            // Calculate the value for the current position in the result
            int resultVal = sum % 10;

            // Update the carry for the next position
            carry = sum / 10;

            // Create a new node for the result
            ListNode* newNode = new ListNode(resultVal);

            // If it's the first node, set it as the head
            if (ans == nullptr) {
                ans = newNode;
                head = ans;
            } else {
                // Otherwise, link it to the previous node
                ans->next = newNode;
                ans = ans->next;
            }

            // Move to the next positions in l1 and l2 (if available)
            if (temp1 != nullptr) temp1 = temp1->next;
            if (temp2 != nullptr) temp2 = temp2->next;
        }

        // If there's still a carry left, create a new node for it
        if (carry != 0) {
            ListNode* newNode = new ListNode(carry);
            ans->next = newNode;
        }

        // Return the head of the result linked list
        return head;
    }
};


//inputes are
// Create two linked lists representing the numbers you want to add
ListNode* l1 = new ListNode(2); // Creating a linked list for the number 2
l1->next = new ListNode(4);
l1->next->next = new ListNode(3);

ListNode* l2 = new ListNode(5); // Creating a linked list for the number 5
l2->next = new ListNode(6);
l2->next->next = new ListNode(4);
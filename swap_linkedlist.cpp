#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Function to swap pairs of nodes in a linked list.
    ListNode* swapPairs(ListNode* head) {
        // If the input list is empty or contains only one element, there's nothing to swap.
        if (head == nullptr || head->next == nullptr) {
            return head; // Return the input list as it is.
        }

        // Temporary pointer to store the next node after the current pair.
        ListNode* temp;
        temp = head->next; // Store the second node in the temp variable.

        // Recursively swap the remaining nodes and update the links.
        head->next = swapPairs(head->next->next);

        // Update the link between the first and second nodes.
        temp->next = head;

        // Return the new head of the swapped pairs.
        return temp;
    }
};

// Function to create a linked list based on user input.
ListNode* createLinkedList() {
    ListNode* head = nullptr; // Initialize an empty linked list.

    // Prompt the user to enter values for the linked list until they choose to stop.
    std::cout << "Enter values for the linked list (enter -1 to stop):\n";
    int val;
    while (true) {
        std::cout << "Enter a value: ";
        std::cin >> val;
        if (val == -1) {
            break; // Stop taking input when -1 is entered.
        }

        // Create a new node with the entered value and add it to the end of the linked list.
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode; // If it's the first node, set it as the head.
        } else {
            // Traverse the list to find the last node and add the new node.
            ListNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    return head;
}

int main() {
    Solution solution;

    // Create a linked list based on user input.
    ListNode* head = createLinkedList();

    // Call the swapPairs function to swap adjacent nodes.
    head = solution.swapPairs(head);

    // Display the swapped linked list.
    std::cout << "Swapped linked list: ";
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Clean up the allocated memory for the linked list.
    current = head;
    while (current != nullptr) {
        ListNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}

#include <iostream>

using namespace std;  // Use the std namespace

class MinStack {
public:
    typedef struct node {
        int v;
        int minUntilNow;
        node* next;
    } node;

    MinStack() : topN(nullptr) {

    }

    void push(int val) {
        node* n = new node;
        n->v = n->minUntilNow = val;
        n->next = nullptr;

        if (topN == nullptr) {
            topN = n;
        } else {
            n->minUntilNow = min(n->v, topN->minUntilNow);
            n->next = topN;
            topN = n;
        }
    }

    void pop() {
        topN = topN->next;
    }

    int top() {
        return topN->v;
    }

    int getMin() {
        return topN->minUntilNow;
    }

private:
    node* topN;
};

int main() {
    MinStack minStack;

    int choice, value;
    while (true) {
        cout << "Menu:\n1. Push\n2. Pop\n3. Get Top\n4. Get Minimum\n5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter a value to push onto the stack: ";
            cin >> value;
            minStack.push(value);
            break;
        case 2:
            minStack.pop();
            break;
        case 3:
            cout << "Top of the stack: " << minStack.top() << endl;
            break;
        case 4:
            cout << "Minimum element in the stack: " << minStack.getMin() << endl;
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
    
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insert_beg(int n) {
        Node* newNode = new Node(n);
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    bool isPalindrome() {
        if (head == NULL) {
            return true; // An empty list is considered a palindrome
        }

        // Create a custom stack-like data structure using pointers
        Node* slow = head;
        Node* fast = head;
        Node* stack = NULL;

        // Push elements from the first half onto the custom stack
        while (fast != NULL && fast->next != NULL) {
            Node* newNode = new Node(slow->data);
            newNode->next = stack;
            stack = newNode;
            slow = slow->next;
            fast = fast->next->next;
        }

        // If the list has an odd number of elements, skip the middle element
        if (fast != NULL) {
            slow = slow->next;
        }

        // Compare the second half with the elements popped from the custom stack
        while (slow != NULL) {
            if (stack->data != slow->data) {
                return false; // Not a palindrome
            }
            Node* temp = stack;
            stack = stack->next;
            delete temp;
            slow = slow->next;
        }

        return true; // It's a palindrome
    }
};

int main() {
    LinkedList list;
    list.insert_beg(1);
    list.insert_beg(2);
    list.insert_beg(3);
    list.insert_beg(2);
    list.insert_beg(1);

    cout << "Linked List Contents:" << endl;
    list.display();

    if (list.isPalindrome()) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}


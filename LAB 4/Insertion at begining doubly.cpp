#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;
    Node* prev; // Add a previous pointer for doubly linked list

public:
    Node* head;

    Node() {
        head = NULL;
    }

    void insert_beg(int n) {
        if (head == NULL) {
            head = new Node();
            head->data = n;
            head->next = NULL;
            head->prev = NULL; // Initialize prev to NULL
        } else {
            Node* p = new Node();
            p->data = n;
            p->next = head;
            p->prev = NULL; // Set prev of new node to NULL
            head->prev = p; // Update prev of the current head
            head = p; // Update head to the new node
        }
    }

    void display() {
        Node* ptr = head;
        if (ptr == NULL) {
            cout << "\nNo data is in the list.." << endl;
            return;
        } else {
            while (ptr != NULL) {
                cout << ptr->data << endl;
                ptr = ptr->next;
            }
        }
    }
};

int main() {
    Node n;
    n.insert_beg(20);
    n.insert_beg(30);
    n.insert_beg(3);
    n.display();
    return 0;
}


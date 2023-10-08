#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

void displayLinkedList(Node* head) {
    cout << "The linked list is:" << endl;
    Node* ptr = head;

    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl<<endl;

    cout << "****head address:***";
    cout << &head << endl;
    cout<<"-----------------------------\n";

    cout << "head content: " << head->data << endl;
    cout <<"-----------------------------\n";

    ptr = head;
    cout << "***ptr address*** ";
    cout << &ptr << endl<<endl;
    

    while (ptr != NULL) {
        cout <<"-----------------------------\n";
        cout << "ptr->data: " << ptr->data << endl;
        cout << "ptr: " << ptr << endl;
        cout << "ptr->next: " << ptr->next << endl;
        ptr = ptr->next;

    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(20);
    head->next->next->next = new Node(30);

    displayLinkedList(head);

    // Free the allocated memory
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}


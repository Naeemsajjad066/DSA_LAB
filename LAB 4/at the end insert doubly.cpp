#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;
    Node* prev;

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
            head->prev = NULL;
        } else {
            Node* p = new Node();
            p->data = n;
            p->next = head;
            p->prev = NULL;
            head->prev = p;
            head = p;
        }
    }

    void insert_end(int n) {
        Node* newNode = new Node();
        newNode->data = n;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->prev = ptr;
        }
    }

    void display() {
        Node* ptr = head;
        if (ptr == NULL) {
            cout << "\nNo data is in the list.." << endl;
            return;
        } else {
            while (ptr != NULL) {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Node n;
    n.insert_beg(20);
    n.insert_beg(30);
    n.insert_beg(3);
    n.insert_end(5);
    n.display();
    return 0;
}


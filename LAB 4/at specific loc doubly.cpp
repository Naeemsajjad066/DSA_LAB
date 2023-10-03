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

    void insert_at_value(int pos, int n) {
        if (head == NULL) {
            cout << "List is empty, cannot insert at position " << pos << endl;
            return;
        }

        Node* ptr = head;
        while (ptr != NULL) {
            if (ptr->data == pos) {
                Node* newNode = new Node();
                newNode->data = n;
                newNode->next = ptr->next;
                newNode->prev = ptr;
                if (ptr->next != NULL) {
                    ptr->next->prev = newNode;
                }
                ptr->next = newNode;
                return;
            }
            ptr = ptr->next;
        }

        cout << "Value " << pos << " not found in the list. Insertion failed." << endl;
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
    n.insert_at_value(20, 50);
    n.display();
    return 0;
}


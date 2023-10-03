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

    void delete_at_value(int val) {
        if (head == NULL) {
            cout << "List is empty. Cannot delete from an empty list." << endl;
            return;
        }

        Node* current = head;

        while (current != NULL) {
            if (current->data == val) {
                if (current->prev != NULL) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }

                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }

                delete current;
                cout << "Node with value " << val << " deleted." << endl;
                return;
            }

            current = current->next;
        }

        cout << "Node with value " << val << " not found in the list." << endl;
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
    
    cout << "Original List:" << endl;
    n.display();
    
    n.delete_at_value(30);
    
    cout << "List after deleting node with value 30:" << endl;
    n.display();
    
    return 0;
}


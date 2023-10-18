#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(NULL) {}

    void push(int val) {
        Node* newNode = new Node(val);
        if (top == NULL) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack is underflow" << endl;
        } else {
            Node* temp = top;
            top = top->next;
            cout << "Popped Value is " << temp->data << endl;
            delete temp;
        }
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
        } else {
            Node* current = top;
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    s.push(2);
    s.push(3);
    s.display();
    s.pop();
    s.display();
    
    return 0;
}


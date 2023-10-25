
#include <iostream>
using namespace std;

class Stack{
    private:
        int* arr;
        int capacity;
        int top;
    
    public:
        Stack(int size) {
            capacity = size;
            arr = new int[size];
            top = -1;
        }
        void push(int val){
            if(top<capacity-1){
                top++;
                arr[top]=val;
            }
            else{
                cout<<"Stack is overflow"<<endl;
            }
        }
        
        void pop(){
            if(top>=0){
                cout<<"poped value is "<<arr[top]<<endl;
                top--;
            }
            else{
                cout<<"Stack is underflow"<<endl;
            }
        }
        void display(){
            if(top==-1){
                cout<<"Stack is empty"<<endl;
            }
            else{
                cout<<"\nStack elements are ";
                for(int i=0; i<=top; i++){
                    cout<<arr[i]<<" ";
                }
                cout<<endl<<endl;
            }
        }

        
};

int main(){
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(6);
    s.push(9);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    return 0;
}




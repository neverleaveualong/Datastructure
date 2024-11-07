#include <iostream>
#define MAX_SIZE 100

using namespace std;

//STACK USE ARRAY

class Stack{
private:
    int top;
    int array[MAX_SIZE];
public:
    Stack():top(-1){}
    
    void push(int value){
        if(top >= MAX_SIZE -1){
            cout<<"Stack overflow \n";
            return;
        }
        array[++top] = value;
    }

    int pop(){
        if(!is_empty()){
            return array[top--];
        }else{
            cout << "Stack is empty";
            return -1;
        }
    }

    int peek() const{
        if(!is_empty()){
            return array[top];
        }else{
            cout << "Stack is empty";
            return -1;
        }
    }

    int size() const {
        return top + 1;
    }

    bool is_empty() const {
        return top == -1;
    }

    void print(){
        for(int i = top; i >= 0; i--){
            if(i==0){
                cout << array[0];
                return;
            }
            cout << array[i] << "->";
            
        }
    }
};

int main(){
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    cout << "제거 된 원소는 " << stack.pop() << "입니다 \n";

    cout << "최상단 원소는 " << stack.peek() << "입니다. \n";

    cout << "스택의 크기는 " <<stack.size() << "입니다. \n";

    stack.print();

    return 0;
}
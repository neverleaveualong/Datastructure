#include <iostream>

using namespace std;

//Stack use LinkedList

class Node {
public:
    int data;
    Node* next;
    Node(int value):data(value),next(nullptr){}
};

class Stack {
private:
    Node* top;
public:
    Stack():top(nullptr){}

    void push(int value){
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    int pop(){
        if(!is_empty()){    
        Node* temp = top;
        int popdata = top->data;
        top = top->next;
        delete temp;
        return popdata;
        }else{
            cout << "Stack is empty";
            return -1;
        }
    }

    int peek(){
        if(!is_empty()){
            return top->data;
        }else{
            cout << "Stack is empty";
            return -1;
        }
    }

    bool is_empty(){
        return top == nullptr;
    }

    int size(){
        int count = 0;
        Node* current = top;
        while(current){
            count++;
            current = current -> next;
        }
        return count;
    }

    void print(){
        cout << "현재 요소는 ";
        Node* current = top;
        while(current){
            if(current->next == nullptr){
                cout << current->data;
                current = current -> next;
            }else{
                cout << current->data << " -> ";
                current = current -> next;
            }
        }
        cout << "입니다." << endl;
    }

    ~Stack() {
        while(!is_empty()){
            pop();
        }
    }
};

int main(){
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    cout << "제거 된 원소는" << stack.pop() << "입니다 \n";

    cout << "최상단 원소는" << stack.peek() << "입니다 \n";

    cout << "스택의 크기는" <<stack.size() << "입니다 \n";

    stack.print();


    return 0;
}
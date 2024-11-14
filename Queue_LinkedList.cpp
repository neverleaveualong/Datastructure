#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int value):data(value),next(nullptr){}
};

class Queue{
private:
    int count;
    Node* front;
    Node* rear;
public:
    Queue():front(nullptr),rear(nullptr),count(0){}
    ~Queue(){
        while(!empty()){
            dequeue();
        }
    }

    void enqueue(int item){
        Node* newnode = new Node(item);

        if(empty()){
            front = rear = newnode;
        } else {
            rear->next = newnode;
            rear = newnode;
        }
        count++;
    }

    void dequeue(){
        if(empty()){
            cout << "Queue is empty" << endl;
            return;
        } else {
            Node* temp = front;
            front = front -> next;

            if(front == nullptr){
                rear = nullptr;
            }
            
            delete temp;
            count-- ;
        }
    }

    int size(){
        return count;
    }

    int top(){
        if(empty()){
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            return front->data;
        }
    }

    bool empty(){
        return (front == nullptr);
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "front element is : " << q.top() << endl;

    q.dequeue();

    cout << "front element is : " << q.top() << endl;

    cout << "Queue'size is : " << q.size() << endl;

    return 0;

}
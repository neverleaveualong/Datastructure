#include <iostream>

using namespace std;

class Queue{
private:
    int* array;
    int front;
    int rear;
    int count;
    int length;

public:,
    Queue(int size){
        array = new int[size];
        front = 0;
        rear = -1;
        count = 0;
        length = size;
    }
    
    ~Queue(){
        delete[] array;
    }

    void enqueue(int value){
        if(!full()){
            rear = (rear+1) % length;
            array[rear] = value;
            count ++;
        } else {
            cout << "queue is full" << endl;
            return;
        }
    }

    void dequeue(){
        if(!empty()){
            front = (front + 1) % length;
            count --;
        } else {
            cout << "queue is empty" << endl;
            return;
        }
    }

    int top(){
        if(!empty()){
            return array[front];
        } else {
            cout << "queue is empty" << endl;
            return -1;
        }
    }

    int size(){
        return count;
    }

    bool empty(){
        return count == 0;
    }

    bool full(){
        return count == length;
    }
};

int main(){
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "q first " << q.top() << endl;

    q.dequeue();

    cout << "q first " << q.top() << endl;

    cout << "q size " << q.size() << endl;

    return 0;
}
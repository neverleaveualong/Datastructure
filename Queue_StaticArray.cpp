#include <iostream>

using namespace std;

class Queue{
private:
    int array[100];
    int front;
    int rear;
    int count;
    int length;

public:
    Queue(int size = 100):
        front(0),
        rear(-1),
        length(size),
        count(0) {}
    
    ~Queue(){}

    void enqueue(int value){
        if(!full()){
            rear = (rear+1) % length;
            array[rear] = value;
            count ++;
        } else {
            cout << "Queue overflow" << endl;
            return ;
        }
    }

    void dequeue(){
        if(!empty()){
            front = (front + 1) % length;
            count --;
        } else {
            cout << "Queue empty" << endl;
            return;
        }
    }

    int top(){
        if(!empty()){
            return array[front];
        } else {
            cout << "stack is empty" << endl;
            return -1;
        }
    }

    int size(){
        return count;
    }

    bool full(){
        return count == length;
    }

    bool empty(){
        return count == 0;
    }
};

int main(){
    Queue legend(5);
    legend.enqueue(10);
    legend.enqueue(20);
    legend.enqueue(30);
    legend.enqueue(40);
    legend.enqueue(50);

    cout << "fisrt element : " << legend.top() << endl;

    legend.dequeue();

    cout << "fisrt element : " << legend.top() << endl;

    cout << "Queue size? : " << legend.size() << endl;

    return 0;
}
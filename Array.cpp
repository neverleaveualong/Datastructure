#include <iostream>
using namespace std;

//Array

class Array {
    private:
    int* arr;
    int size;
    int capacity;

    public:
    Array(int cap){
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    void add(int value){
        if(size < capacity){
            arr[size++] = value;
        } else {
            cout << "Array is full" << endl;
        }
    }

    void remove(){
        if (size > 0){
            size--;
        } else {
            cout << "Array is empty" << endl;
        }
    }


    int get(int index){
        if(index >= 0 && index < size){
            return arr[index];
        }else {
            cout << "Index out of bound" << endl;
            return -1;
        }
    }

    int getsize(){
        return size;
    }

    void print(){
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Array(){
        delete[] arr;
    }
};

int main(){
    Array arr(5);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    cout << "배열 :";
    arr.print();

    arr.remove();
    cout << "제거된 배열: ";
    arr.print();

    cout << "2번째 인덱스의 값 " << arr.get(2) <<endl;

    cout << "Size: " << arr.getsize() <<endl;
    
    return 0;
}
#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int value):data(value),prev(nullptr),next(nullptr){}
};

class DoublyLinkedList{
private:
    Node* head;
    int count;
public:
    DoublyLinkedList():head(nullptr),count(0){}

    void insert(int item, int position){
        if(position < 0 || position > count){
            cout << "Invalid Position" << endl;
            return;
        }
        Node* newnode = new Node(item);

        if(head == nullptr){
            head = newnode;
        } else {
            if(position == 0){
                newnode->next = head;
                head->prev = newnode;
                head = newnode;
            } else {
                Node* current = head;

                for(int i = 0; i<position -1; i++){
                    current = current->next;
                }

                newnode->next = current->next;
                if(current->next != nullptr){
                    current->next->prev = newnode;
                }
                current->next = newnode;
                newnode->prev = current;
            }
        }
        count++;
    }

    void remove(int position){
        if(position < 0 || position >= count){
            cout << "Invalid Position" << endl;
            return;
        }

        if(head->prev == nullptr && head->next == nullptr){
            delete head;
            head = nullptr;
        } else {
            if(position == 0){
                Node* temp = head;
                head = head->next;
                head->prev = nullptr;
                delete temp;
            } else {
                Node* current = head;

                for(int i = 0; i < position-1; i++){
                    current = current->next;
                }

                Node* temp = current->next;
                current->next = current->next->next;

                if(current->next != nullptr){
                    current->next->prev = current;
                }

                delete temp;
            }
        }
        count--;
    }

    void display(){
        Node* current = head;
        while (current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    int size() const{
        return count;
    }
};

int main() {
    DoublyLinkedList list;

    // Insert elements
    list.insert(10, 0); // List: 10
    list.insert(20, 1); // List: 10 20
    list.insert(30, 2); // List: 10 20 30
    list.insert(40, 3); // List: 10 20 30 40
    list.insert(50, 4); // List: 10 20 30 40 50

    cout << "Original list: ";
    list.display();

    // Remove the last element (position = 4)
    list.remove(4); // Removes 50
    cout << "List after removing last element: ";
    list.display();

    // Remove the last element (position = 3)
    list.remove(3); // Removes 40
    cout << "List after removing last element again: ";
    list.display();

    return 0;
}


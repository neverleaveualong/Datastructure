#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int value):data(value),prev(nullptr),next(nullptr){}
};

class CircularDoublyLinkedList{
private:
    Node* head;
    int count;
public:
    CircularDoublyLinkedList():head(nullptr),count(0){}

    void insert(int item, int position){
        if(position < 0 || position > count){
            cout << "Invalid Position" << endl;
            return;
        }

        Node* newnode = new Node(item);

        if(head==nullptr){
            head = newnode;
            head->next = head;
            head->prev = head;
        } else {
            if(position == 0){
                Node* current = head;
                while(current->next!=head){
                    current = current->next;
                }
                current->next = newnode;
                newnode->prev = current;
                head->prev = newnode;
                newnode->next = head;
                head = newnode;
            }  else {
                Node* current = head;

                for(int i = 0; i < position-1; i++){
                    current=current->next;
                }

                newnode->next = current->next;
                current->next->prev = newnode;
                current->next = newnode;
                newnode->prev = current;
            }
        }
        count++;
    }

    void remove(int position){

        if(head == nullptr || position < 0 || position >= count) {
            cout << "Invalid Position" << endl;
            return;
        }

        if(head->next == head){
            delete head;
            head = nullptr;
        } else {
            if(position == 0){
                Node* current = head;

                while(current->next != head){
                    current = current->next;
                }

                Node* temp = head;
                current->next = head->next;
                head->next->prev = current;
                head = head->next;
                delete temp;


            } else {
                Node* current = head;

                for (int i = 0 ; i < position - 1; i++){
                    current = current->next;
                }
                Node* temp = current->next;
                current->next = current->next->next;
                current->next->prev = current;

                delete temp;

            }
        }
        count--;
    }

    int size() const{
        return count;
    }

    void print(){
        if(head == nullptr) return;

        Node* current = head;
        do{
            cout << current->data << " ";
            current = current -> next;
        } while (current != head);
        cout << endl;
    }
};

int main(){
    CircularDoublyLinkedList list;

    list.insert(10,0);
    list.insert(20,1);
    list.insert(30,2);
    list.insert(40,3);

    list.print();

    cout << "list size = " << list.size() << endl;

    list.remove(0);

    list.print();

    list.remove(2);

    list.print();

    return 0;
}
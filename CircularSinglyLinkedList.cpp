#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int value):data(value),next(nullptr){}
};

class CircularSinglyLinkedList{
private:
    Node* head;
    int count;

public:
    CircularSinglyLinkedList() : head(nullptr), count(0) {}

    ~CircularSinglyLinkedList() {
        while (count > 0) {
            removeatfirst();
        }
    }

    void addatfirst(int item){
        Node* newnode = new Node(item);
        if(head==nullptr){
            head = newnode;
            head->next = newnode;
        } else{
            Node* current = head;
            while(current->next != head){
                current = current->next;
            }
            current->next = newnode;
            newnode->next = head;
        }
        count ++;
    }

    void removeatfirst(){
        if(head == nullptr){
            cout << "List is empty" << endl;
            return;
        }
        if(head->next == head){
            delete head;
            head = nullptr;
        } else{
            Node* current = head;
            Node* temp = head;
            while(current->next != head){
                current = current->next;
            }
            current->next = head->next;
            head = head->next;
            delete temp;
        }
        count--;
    }

    void insert(int item, int position){

        if(position < 0 || position > count){
            cout << "Invaild postition" << endl;
            return;
        }

        Node* newnode = new Node(item);

        if(head == nullptr){
            head = newnode;
            head->next = newnode;
        } else if (position == 0 ){
            Node* current = head;

            while(current->next != head){
                current = current->next;
            }

            current->next = newnode;
            newnode->next = head;
            head = newnode;

        } else {
            Node* current = head;
            for(int i = 0; i < position - 1; i++){
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
        }
        count++;
    }

    void remove(int position){
        if (position < 0 || position >= count){
            cout << "Invalid position" << endl;
            return;
        }

        if (position == 0){
            Node* temp = head;

            if(head->next == head){
                head = nullptr;
            } else {
                Node* current = head;

                while(current->next != head){
                    current = current->next;
                }
                current->next = head->next;
                head = head -> next;
                
            }
            delete temp;
        } else {
            Node* current = head;
            
            for(int i = 0; i<position-1; i++){
                current = current->next;
            }

            Node* temp = current->next;

            current->next = current->next->next;

            delete temp;
            
        }
        count--;
    }

    int size() const {
        return count;
    }

    void display(){
        if (head == nullptr){
            cout << "List is empty" << endl;
            return;
        }
        Node* current = head;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while(current != head);
        cout << endl;
    }

    bool search(int item){

        if(head == nullptr){
            cout << "List is empty" << endl;
            return false;
        }

        Node* current = head;

        do{
            if(current->data == item){
                return true;
            } 
            current = current->next;
        } while ( current != head);
        return false;
    }
};

int main() {
    CircularSinglyLinkedList list;
    list.addatfirst(10);
    list.addatfirst(20);
    list.insert(30, 1);
    list.display();  // 출력: 20 -> 30 -> 10 -> 
    list.insert(50,3);
    list.display();

    list.remove(1);
    list.display();  // 출력: 20 -> 10 -> 

    cout << "Size: " << list.size() << endl;  // 출력: Size: 2
    cout << (list.search(10) ? "Found" : "Not Found") << endl;  // 출력: Found

    return 0;
}
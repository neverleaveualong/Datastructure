#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int value):data(value),next(nullptr){}
};

class SinglyLinkedList{
private:
    Node* head;
    int count;
public: 
    SinglyLinkedList():head(nullptr),count(0){}

    ~SinglyLinkedList(){
        while(head != nullptr){
            remove();
        }
    }

    void add(int item){
        Node* newnode = new Node(item);

        if(head == nullptr){
            head = newnode;
        } else {
            Node* current = head;
            while(current -> next != nullptr){
                current = current->next;
            }
            current->next = newnode;
        }

        count++;
    }

    void remove(){
        if(head==nullptr){
            cout << "list is empty" << endl;
            return;
        } 
        
        if (head->next == nullptr){
            delete head;
            head = nullptr;
        } else {
            Node* current = head;
            while(current -> next -> next != nullptr){
                current = current -> next;
            }

            Node* temp = current->next;
            current->next = nullptr;
            delete temp;

        }
        count-- ;
    }

    void removeatfirst(){
        if(head == nullptr){
            cout << "list is empty" << endl;
        } else {
        Node* temp = head;
        head = head->next;
        delete temp;
        }
        count--;
    }

    int size() const{
        return count;
    }

    bool search(int item){
        Node* current = head;
        while(current != nullptr){
            if(current->data == item){
                return item;
            }
            current = current->next;
        }
        return false;
    }

    void insertAt(int item, int position){
        if ( position < 0 || position > count){
            cout << "Invaild position" << endl;
            return;
        }
        Node* newnode = new Node(item);
        if(position == 0){
            newnode->next = head;
            head = newnode;
        } else {
            Node* current = head;
            for(int i = 0; i < position -1; i++){
                current = current ->next;
            }
            newnode->next = current->next;
            current->next = newnode;
        }
        count++;
    }

    void removeAt(int position){
        if (position < 0 || position >= count){
            cout << "Inavild position" <<endl;
            return;
        }
        if (position = 0){
            removeatfirst();
        } else {
            Node* current = head;
            for (int i = 0; i < position -1; ++i){
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            count--;
        }
    }

    void display(){
        Node* current = head;
        while(current != nullptr){
            cout << current->data << " -> ";
            current = current->next;
        }
        
        cout << "X" << endl;
    }
};

int main(){
    SinglyLinkedList list;

    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);

    cout << "List after adding elements: ";
    list.display();

    cout << "Size of the list: " << list.size() << endl;

    int searchValue = 20;
    cout << "Searching for " << searchValue << ": ";
    cout << (list.search(searchValue) ? "Found" : "Not Found") << endl;

    list.insertAt(25, 2);
    cout << "List after inserting 25 at position 2: ";
    list.display();

    list.removeAt(3);
    cout << "List after removing element at position 3: ";
    list.display();

    list.removeatfirst();
    cout << "List after removing the first element: ";
    list.display();

    list.remove();
    cout << "List after removing the last element: ";
    list.display();

    cout << "Final size of the list: " << list.size() << endl;

}
#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
};

class LinkedList{
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList(){
        head = tail = nullptr;
        size=0;
    }

    void InsertAtHead(int val){                 // (a)  Insertion at the Haed
        Node* new_node = new Node(val);
        if(size==0) head = tail = new_node;
        else{
            new_node->next = head;
            head = new_node;
        }
        size++;
    }

    void InsertAtTail(int val){                 // (b) Insertion at the Tail
        Node* new_node = new Node(val);
        if(size==0) head = tail = new_node;
        else{
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }

    void InsertAtPosition(int val ,int postion){  // (c) Insertion at the Positon 
        if(postion==0){
            InsertAtHead(val);
            return;
        }
        if(postion==size){
            InsertAtTail(val);
            return;
        }
        else{
            Node* new_node = new Node(val);
            Node* temp = head;
            int current_pos = 0;
            while(current_pos!=postion-1){
                temp = temp->next;
                current_pos++;
            }
            // temp is pointing to node at position-1
            new_node->next = temp->next;
            temp->next = new_node;
            size++;
        }
    }

    void Display(){                               // display/print/traversal of the linked list 
        Node* temp = head;
        while(temp!=nullptr){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"Null\n";
    }

};

int main(){

    LinkedList ll;
    ll.InsertAtHead(1);
    ll.InsertAtHead(2);
    ll.InsertAtHead(3);
    ll.InsertAtTail(4);
    ll.InsertAtPosition(5,2);

    ll.Display();
    cout<< ll.size;

    return 0;
}
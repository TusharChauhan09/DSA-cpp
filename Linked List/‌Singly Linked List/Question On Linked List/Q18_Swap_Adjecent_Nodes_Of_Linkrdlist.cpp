// Q18
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void Insert(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void Display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

Node* Swap_Adjecemt(Node* &head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }


    Node* sec = head->next;
    head->next = Swap_Adjecemt(sec->next);
    sec->next = head; 

    return sec;
}

int main() {
    LinkedList l1;
    l1.Insert(1);
    l1.Insert(2);
    l1.Insert(3);
    l1.Insert(4);
    l1.Insert(5);
    l1.Insert(6);
    l1.Display();
    cout<<"\n";

    l1.head = Swap_Adjecemt(l1.head);
    l1.Display();

    return 0;
}

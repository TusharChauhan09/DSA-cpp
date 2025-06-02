#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = nullptr;
    }

    // ✅ Display list
    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->val << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // ✅ Insertion at head
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            newNode->next = newNode;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    // ✅ Insertion at tail
    void insertAtTail(int val) {
        if (!head) {
            insertAtHead(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    // ✅ Insertion at any index (0-based)
    void insertAtIndex(int index, int val) {
        if (index == 0) {
            insertAtHead(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;

        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
            if (temp == head) {
                cout << "Index out of bounds\n";
                return;
            }
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // ✅ Deletion at head
    void deleteAtHead() {
        if (!head) return;

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        Node* tail = head;

        while (tail->next != head)
            tail = tail->next;

        head = head->next;
        tail->next = head;

        delete temp;
    }

    // ✅ Deletion at tail
    void deleteAtTail() {
        if (!head) return;

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != head)
            temp = temp->next;

        Node* delNode = temp->next;
        temp->next = head;
        delete delNode;
    }

    // ✅ Deletion at index
    void deleteAtIndex(int index) {
        if (!head) return;

        if (index == 0) {
            deleteAtHead();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
            if (temp->next == head) {
                cout << "Index out of bounds\n";
                return;
            }
        }

        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    // ✅ Update value at index
    void updateAtIndex(int index, int newVal) {
        if (!head) return;

        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
            if (temp == head) {
                cout << "Index out of bounds\n";
                return;
            }
        }
        temp->val = newVal;
    }
};

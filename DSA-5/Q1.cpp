#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;
public:
    List() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void pop_front() {
        if (head == NULL) {
            cout << "LL is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == NULL)
            tail = NULL;
        delete temp;
    }

    void pop_back() {
        if (head == NULL) {
            cout << "LL is empty\n";
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void insert(int val, int pos) {
        if (pos < 0) {
            cout << "invalid pos\n";
            return;
        }
        if (pos == 0) {
            push_front(val);
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp == NULL) {
                cout << "invalid pos\n";
                return;
            }
            temp = temp->next;
        }
        if (temp == tail) {
            push_back(val);
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int search(int key) {
        Node* temp = head;
        int idx = 0;
        while (temp != NULL) {
            if (temp->data == key)
                return idx;
            temp = temp->next;
            idx++;
        }
        return -1;
    }
};

int main() {
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.print();
    ll.pop_back();
    ll.print();
}

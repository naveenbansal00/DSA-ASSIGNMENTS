#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
    data = val;
    next = NULL;}
};

class circularList {
    Node* head;
    Node* tail;
public:
    circularList() {
    head = tail = NULL;
    }

void push_front(int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
    head = tail = newNode;
    tail->next = head;
    return;}
    newNode->next = head;
    head = newNode;
    tail->next = head;}

void push_back(int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
    head = tail = newNode;
    tail->next = head;
    return;}
    tail->next = newNode;
    tail = newNode;
    tail->next = head;}

void pop_front() {
    if (head == NULL) {
    cout << "CLL is empty\n";
    return;}
    if (head == tail) {
    delete head;
    head = tail = NULL;
    return;}
    Node* temp = head;
    head = head->next;
    tail->next = head;
    delete temp;}

void pop_back() {
    if (head == NULL) {
    cout << "CLL is empty\n";
    return;}
    if (head == tail) {
     delete head;
    head = tail = NULL;
    return;}
    Node* temp = head;
    while (temp->next != tail)
    temp = temp->next;
    delete tail;
    tail = temp;
    tail->next = head;}

void insert(int val, int pos) {
    if (pos < 0) {
    cout << "invalid pos\n";
    return;}
    if (pos == 0) {
    push_front(val);
    return;}
    Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
    temp = temp->next;
    if (temp == head) {
    cout << "invalid pos\n";
    return;}}
    if (temp == tail) {
    push_back(val);
    return;}
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;}

void print() {
    if (head == NULL) {
    cout << "CLL is empty\n";
    return;}
    Node* temp = head;
    do{
    cout << temp->data << "->";
    temp = temp->next;} 
    while (temp != head);
    cout << "(back to head)\n";}

int search(int key) {
    if (head == NULL)
    return -1;
    Node* temp = head;
    int idx = 0;
    do {
    if (temp->data == key)
    return idx;
    temp = temp->next;
    idx++;} 
    while (temp != head);
    return -1;}
};

int main() {
    circularList cll;
    cll.push_front(1);
    cll.push_front(2);
    cll.push_front(3);
    cll.print();
    cll.pop_back();
    cll.print();
    cll.push_back(4);
    cll.insert(5, 2);
    cll.print();
    cout << "Index of 4: " << cll.search(4) << endl;
}

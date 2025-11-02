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
void iscircular(){
    if (tail->next == head)
    cout << "The linked list is circular.";
    else
    cout << "The linked list is not circular.";}
   
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
}; 

int main (){
circularList CL;
CL.push_back(1);
CL.push_back(2);
CL.push_back(3);
CL.print();
CL.iscircular();

}
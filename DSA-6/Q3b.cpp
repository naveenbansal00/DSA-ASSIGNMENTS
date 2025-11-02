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

void size(){
    Node* temp;
    if(head==NULL){cout<<"CL is empty" ;return;}
    temp=head;
    int count=1;
    while(temp->next!=head){
    temp=temp->next;
    count++;}
    cout<<"size of CL is "<<count;}
        

void print() {
    if (head == NULL) {
    cout << "CL is empty\n";
    return;}
    Node* temp = head;
    do{
    cout << temp->data << "->";
    temp = temp->next;} 
    while (temp != head);
    cout << "(back to head)\n";}
};

int main() {
    circularList cll;
    cll.push_front(3);
    cll.push_front(2);
    cll.push_front(1);
    cll.print();
    cll.size();
       
}

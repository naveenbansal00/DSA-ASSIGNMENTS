#include<iostream>
using namespace std ;
class Node {
public :
    int data;
    Node* next;
    Node* prev;

    Node(int val){
    data = val ;
    next = NULL ;
    prev = NULL; }
};

class DoubleList {
    Node* head ;
    Node* tail ;
public :
DoubleList(){
    head = tail = NULL ;}

void push_front(int val){
    Node* newNode = new Node(val);  // dynamically
    if(head== NULL){
    head=tail=newNode;
    return ;} 
    else{
    newNode->next = head;
    head->prev =newNode;
    head = newNode;}}
    
bool hasEvenParity(int n) {
    int count = 0;
    while (n) {
    if (n & 1)
    count++;
    n = n >> 1;}
    return (count % 2 == 0);}

void evenparitydelete(){
    Node* curr =head;
    while(curr!=NULL){
    Node* nextNode = curr->next;
    if (hasEvenParity(curr->data)) {
    if (curr->prev!=NULL)
    curr->prev->next = curr->next;
    else
    head = curr->next; 
    if (curr->next!=NULL)
    curr->next->prev = curr->prev;
    else
    tail = curr->prev; 
    delete curr;}
    curr = nextNode;}}

void print() {
    Node* temp =head ;
    while(temp!=NULL){
    cout<<temp->data<<"<=>";
    temp=temp->next;}
    cout<<"NULL"<<endl;}
};

int main (){
DoubleList DL ;
DL.push_front(3);
DL.push_front(2);
DL.push_front(1);
DL.print();
DL.evenparitydelete();
DL.print();
}
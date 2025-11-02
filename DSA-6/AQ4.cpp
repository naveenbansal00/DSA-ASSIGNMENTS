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
    
void correctPointer(){
    if (!head){
    return;}
    Node *temp = head;
    while (temp->next != NULL){
    if (temp->next->prev != temp){
    temp->next->prev = temp;}
    temp = temp->next;}}


void print() {
    Node* temp =head ;
    while(temp!=NULL){
    cout<<temp->data<<"<=>";
    temp=temp->next;}
    cout<<"NULL"<<endl;}
};
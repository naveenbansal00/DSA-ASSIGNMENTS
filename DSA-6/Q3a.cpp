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

void size(){
    Node* temp;
    if(head==NULL){cout<<"DL is empty" ;return;}
    temp=head;
    int count=0;
    while(temp!=NULL){
    temp=temp->next;
    count++;}
    cout<<"size of DL is "<<count;}
    
void print(){
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
DL.size();
}
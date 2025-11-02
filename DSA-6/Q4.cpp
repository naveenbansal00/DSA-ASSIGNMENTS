#include<iostream>
using namespace std ;
class Node {
public :
    char data;
    Node* next;
    Node* prev;

    Node(char val){
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

bool palindrome(){
    if (head == NULL || head->next == NULL)
    return true; 
    Node* st;
    Node* end;
    st=head;
    end=tail;
    while (st != NULL && end != NULL && st != end && end->next != st){
    if(st->data!=end->data){ 
    return false ;}
    st=st->next;
    end=end->prev;}
    return true ;}
    
void print(){
    Node* temp =head ;
    while(temp!=NULL){
    cout<<temp->data<<"<=>";
    temp=temp->next;}
    cout<<"NULL"<<endl;}
};

int main (){
DoubleList DL ;
DL.push_front('a');
DL.push_front('b');
DL.push_front('4');
DL.print();
cout << (DL.palindrome() ? "Palindrome" : "Not Palindrome") << endl;
}
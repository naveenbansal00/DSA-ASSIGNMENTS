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
    
void push_back(int val){
    Node* newNode = new Node(val);
    if(head == NULL){
    head = tail = newNode;
    return;}
    else {
    tail->next = newNode;  
    newNode->prev= tail;
    tail = newNode;}}
    
void pop_front() {
    if(head==NULL){
    cout<<"DL is empty \n";
    return ;}
    Node* temp = head;
    head = head->next;
    if(head!=NULL)
    head->prev = NULL;
    temp->next = NULL;
    delete temp ; }
   
void pop_back() {
    if(head==NULL){
    cout<<"DL is empty \n";
    return ;}
    Node* temp = tail ;
    tail=tail->prev ;
    if(tail!=NULL)
    tail->next = NULL;
    temp->prev = NULL;
    delete temp ;}

void insert(int val,int idx){
    if(idx<0){
    cout<< "invalid pos \n ";
    return ;}
    if(idx==0){
    push_front(val);
    return ;}
    Node* temp = head ;
    for(int i=0;i<idx-1;i++){
    if(temp==NULL){
    cout<<"invalid pos \n ";
    return ;}
    temp=temp->next;}
    if (temp == tail) {
    push_back(val);
    return;}
    Node* newNode = new Node(val);  
    newNode->next =temp->next;
    newNode->prev =temp ;
    temp->next->prev=newNode;
    temp->next =newNode;}

void Delete(int idx){
    if(idx<0){
    cout<< "invalid pos \n ";
    return ;}
    if(idx==0){
    pop_front();
    return ;}
    if(head==NULL){
    cout<<"DL is empty \n";
    return;}
    Node* temp = head ;
    for(int i=0;i<idx-1;i++){
    if(temp==NULL){
    cout<<"invalid pos \n ";
    return ;}
    temp=temp->next;}
    if (temp == tail) {
    pop_back();
    return;}
    Node* delNode = temp->next;  
    if (delNode == NULL) {
    cout << "invalid pos\n";
    return;}
    temp->next = delNode->next;
    delNode->next->prev = temp;
    delete delNode;}

int search (int key ){
    Node* temp =head ;
    int idx =0;
    while(temp!=NULL){
    if(temp->data==key)
    return idx ;
    temp=temp->next;
    idx++;}
    return -1 ;}
    
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
DL.pop_back();
DL.pop_front();
DL.print();
cout<< DL.search(2);
}
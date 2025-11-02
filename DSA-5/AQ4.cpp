#include<iostream>
using namespace std ;
class Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class List {
Node* head ;
Node* tail ;
public :
  List(){
    head = tail = NULL ;}

    void push_back(int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = tail = newNode;
        return;
    }
    else {
        tail->next = newNode;  
        tail = newNode;     
    }
}
void print(){
       Node* temp =head ;
       while(temp!=NULL){
         cout<<temp->data<<"->";
         temp=temp->next;}
        cout<<"NULL"<<endl;}  
        


void rotate_list(int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return;
         Node* temp = head;
        int len = 1;
        while (temp->next != NULL) {
            temp = temp->next;
            len++;}
        tail = temp;
        tail->next = head;
        k = k % len;
        int stepsToNewHead = len - k;
        temp = head;
        for (int i = 1; i < stepsToNewHead; i++) {
                   temp = temp->next;}
        head = temp->next;
        temp->next = NULL;
    }};

int main() {
    List A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);
    cout<<"list before rotaion"<<endl;
    A.print();
    A.rotate_list( 2 );
    cout<<"list after rotaion"<<endl;
    A.print();

    return 0; }
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
 void createCycle(int pos) {
        if (pos <= 0) return;
        Node* temp = head;
        Node* startNode = NULL;
        int count = 1;
        while (temp->next != NULL) {
            if (count == pos) startNode = temp;
            temp = temp->next;
            count++;
        }
        if (startNode != NULL) {
            temp->next = startNode; // creating cycle
        }
    }

 void printList(){
       Node* temp =head ;
       while(temp!=NULL){
         cout<<temp->data<<"->";
         temp=temp->next;}
        cout<<"NULL"<<endl;}  
        
Node* getHead() { return head; }
};
void removecycle(Node* prev){
    prev->next=NULL;
}
   Node *detectCycle(Node *head) {
    Node* slow = head ;
    Node* fast = head ;
    bool iscycle = false ;
    while(fast != NULL && fast->next != NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){iscycle =true; break ;} 
        }

        if(!iscycle){return NULL ;}

        slow  = head ;
        Node* prev ;
        while(slow!=fast){
            slow=slow->next;
            prev =fast;
            fast=fast->next;
        }
         removecycle(prev);
        return slow;}

 
int main() {
    List A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);

    
    A.createCycle(3);
 
    Node* headA = A.getHead();
    Node* startOfCycle = detectCycle(headA);

    if (startOfCycle) {
        cout << "Cycle detected at node with value: " << startOfCycle->data << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    
    cout << "List after cycle removal: ";
    A.printList();

    return 0;
}
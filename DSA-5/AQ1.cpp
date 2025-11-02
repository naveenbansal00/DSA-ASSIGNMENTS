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
Node* getHead() { return head; }
};
Node* findIntersectionNode (Node *A, Node *B, int difference) {
	while(difference > 0) {
		A = A->next;
		difference--;
	}
	while (A != NULL && B!= NULL) {
		if (A==B) {
			return A;
		}
		A = A->next;
		B = B->next;
	}
	return NULL;
}

Node* measure_length(Node *A, Node *B) {
    int firstLength = 0;
	Node* firstCurrNode = A;
	while (firstCurrNode != NULL) {
		firstLength++;
		firstCurrNode = firstCurrNode->next;
	}
	int secondLength = 0;
	Node* secondCurrNode = B;
	while (secondCurrNode != NULL) {
		secondLength++;
		secondCurrNode = secondCurrNode->next;
	}
	if (firstLength < secondLength) {
		return findIntersectionNode (B, A, secondLength - firstLength);
	} else {
		return findIntersectionNode (A, B, firstLength - secondLength);
	}
}
int main (){
List A;
List B;
A.push_back(1);
A.push_back(2);
A.push_back(3);
A.push_back(4);
A.push_back(5);
B.push_back(1);
B.push_back(2);
B.push_back(3);
B.push_back(4);
B.push_back(5);
Node* headA = A.getHead();
Node* headB = B.getHead();

Node* tempB = headB;
    while (tempB->next != NULL)
        tempB = tempB->next;

        // Connect tail of B to 3rd node of A (intersection)
    Node* tempA = headA->next->next; // Node with value 3
    tempB->next = tempA;

    Node* intersection = measure_length(headA, headB);

    if (intersection != NULL)
        cout << "Intersection Node found at value: " << intersection->data << endl;
    else
        cout << "No intersection found." << endl;

    return 0;


} 
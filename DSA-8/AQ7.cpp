#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


void bstToDLL(Node* root, Node*& head, Node*& prev) {
    if (root==NULL) return;
    bstToDLL(root->left, head, prev);
    if (!prev) head = root;
    else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;
    bstToDLL(root->right, head, prev);
}


Node* mergeDLL(Node* head1, Node* head2) {
    if (head1==NULL) return head2;
    if (head2==NULL) return head1;

    Node* head = NULL;
    Node* tail = NULL;

    if (head1->data < head2->data) {
        head = tail = head1;
        head1 = head1->right;
    } else {
        head = tail = head2;
        head2 = head2->right;
    }

    while (head1 && head2) {
        if (head1->data < head2->data) {
            tail->right = head1;
            head1->left = tail;
            tail = head1;
            head1 = head1->right;
        } else {
            tail->right = head2;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
        }
    }

    if (head1) {
        tail->right = head1;
        head1->left = tail;
    } else if (head2) {
        tail->right = head2;
        head2->left = tail;
    }

    return head;
}


void printDLL(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

int main() {
    // BST 1
    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    // BST 2
    Node* root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    Node* head1 = NULL, *prev1 = NULL;
    bstToDLL(root1, head1, prev1);
    prev1->right = NULL;

    Node* head2 = NULL, *prev2 = NULL;
    bstToDLL(root2, head2, prev2);
    prev2->right = NULL;

    Node* merged = mergeDLL(head1, head2);

    printDLL(merged);
}

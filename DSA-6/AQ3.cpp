#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;
    ListNode* prev;
    ListNode(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head) return NULL;
    ListNode* currentNode = head;
    ListNode* prevNode = NULL;
    ListNode* nextNode = NULL;
    int count = 0;
    while (currentNode && count < k) {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        currentNode->prev = nextNode;
        prevNode = currentNode;
        currentNode = nextNode;
        count++;
    }
    if (currentNode) {
        head->next = reverseKGroup(currentNode, k);
        if (head->next)
            head->next->prev = head;
    }
    return prevNode;
}

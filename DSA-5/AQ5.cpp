#include <iostream>
using namespace std;

class Node {
public:
    int coeff, pow;
    Node* next;
    Node(int c, int p) {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

class Polynomial {
public:
    Node* head;
    Polynomial() { head = NULL; }

    void insert(int c, int p) {
        Node* n = new Node(c, p);
        if (!head) head = n;
        else {
            Node* t = head;
            while (t->next) t = t->next;
            t->next = n;
        }
    }

    Polynomial add(Polynomial b) {
        Polynomial p3;
        Node* p1 = head;
        Node* p2 = b.head;
        while (p1 && p2) {
            if (p1->pow > p2->pow) {
                p3.insert(p1->coeff, p1->pow);
                p1 = p1->next;
            } else if (p1->pow < p2->pow) {
                p3.insert(p2->coeff, p2->pow);
                p2 = p2->next;
            } else {
                p3.insert(p1->coeff + p2->coeff, p1->pow);
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        while (p1) {
            p3.insert(p1->coeff, p1->pow);
            p1 = p1->next;
        }
        while (p2) {
            p3.insert(p2->coeff, p2->pow);
            p2 = p2->next;
        }
        return p3;
    }

    void display() {
        Node* t = head;
        while (t) {
            cout << t->coeff << "x^" << t->pow;
            if (t->next) cout << " + ";
            t = t->next;
        }
        cout << endl;
    }
};

int main() {
    Polynomial p1, p2, p3;
    p1.insert(5,2);
    p1.insert(4,1);
    p1.insert(2,0);
    p2.insert(5,1);
    p2.insert(5,0);
    p3 = p1.add(p2);
    p1.display();
    p2.display();
    p3.display();
    return 0;
}

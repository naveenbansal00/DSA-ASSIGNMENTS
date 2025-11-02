#include<iostream>
using namespace std ;
class MyStack {
public:
queue <int> q;


void push(int x) {   // push      O(n)
 int size =q.size();
  q.push(x);
 for (int i = 0; i < size; i++) {
    q.push(q.front());
    q.pop();
}
}
    
int pop() {         // pop
int ans =q.front() ;
q.pop();
return ans ;}

int top() {         // top
return q.front() ;}

bool empty() {         // empty
return q.empty();}
};


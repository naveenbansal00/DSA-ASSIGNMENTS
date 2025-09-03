#include<iostream>
using namespace std ;
class Queue {
    int* a;
    int capacity;
    int r,f;
public :
Queue(int size){
     capacity =size ;
    a =new int[capacity];
   
    r=-1;
    f=0;}

void enqueue(int x){
if(isfull()){cout<<"queue is full"<<endl;}
else{r++;
a[r]=x;;}}

void dequeue (){
    if(isempty()){cout<<"queue is empty"<<endl;}
    else{f++;
    }}

bool isempty(){
    return f > r;}

bool isfull() {
    return r == capacity-1;}   

int peek (){ return a[f] ;}

    void display() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
        } else {
            for (int i = f; i <= r; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }};
int main () {
Queue c(3) ;
c.enqueue(1);
c.enqueue(2);
c.enqueue(3);
c.display(); // 1 2 3
c.dequeue();
c.display(); // 2 3
c.enqueue(4);
c.display(); // 2 3 4 


}

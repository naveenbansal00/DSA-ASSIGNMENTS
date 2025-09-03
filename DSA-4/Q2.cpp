#include<iostream>
using namespace std ;
class circularqueue {
    int* a;
    int cs,capacity;
    int r,f;
public :
circularqueue(int size){
    capacity =size ;
    a =new int[capacity];
    
    r=-1;
    f=0;
    cs=0;}

void enqueue(int x){
if(capacity==cs){cout<<"queue is full"<<endl;}
else{r=(r+1)%capacity;
a[r]=x;cs++;}}

void dequeue (){
    if(cs==0){cout<<"queue is empty"<<endl;}
    else{f=(f+1)%capacity;
    cs--;}}

bool isempty(){
    return cs==0 ;}

bool isfull() {
    return capacity == cs ;}   

int peek (){ return a[f] ;}

void display (){
            if(isempty()){ cout<<" queue is empty"<<endl; }
            else { int count = cs;
        int i = f;
        while (count--) {
            cout << a[i] << " ";
            i = (i + 1) % capacity;
            
        }
        cout << endl; }}
    
        ~circularqueue() {
        delete[] a;
    }
};
int main () {
circularqueue c(3) ;
c.enqueue(1);
c.enqueue(2);
c.enqueue(3);
//c.display(); // 1 2 3
c.dequeue();
// c.display(); // 2 3
c.enqueue(4);
c.display(); // 2 3 4 


}

#include<iostream>
#include<queue>
using namespace std ;
int main () {
queue <int> q1;
queue <int> q2;
queue <int> q3;
q1.push(4);
q1.push(7);
q1.push(11);
q1.push(20);
q1.push(5);
//q1.push(9);
int half;
if(q1.size()%2==0){
 half = q1.size()/2 ;}
else {  half = (q1.size()/2 + 1);}

for(int i=1;i<=half;i++){
    q2.push(q1.front());
    q1.pop();
}

while(!q2.empty()){
    q3.push(q2.front());
    q2.pop();

   if(!q1.empty()){ q3.push(q1.front());
    q1.pop();}

}


while (!q3.empty()) {
    cout << q3.front() <<endl;
    q3.pop();
}




}
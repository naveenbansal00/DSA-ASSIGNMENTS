#include<iostream>
#include<list>
using namespace std ;
int main (){
list<int> ll ;
ll.push_back(1);
ll.push_back(2);
ll.push_back(1);
ll.push_back(2);
ll.push_back(1);
ll.push_back(3);
ll.push_back(1);
for (int val : ll)
    cout << val << "->";
    cout<<"NULL";
int key = 1;
int count = 0;
for(int val : ll){
    if(val==key){
        count++;
    }}
cout<<"\ncount of key is "<<count;
for(auto value=ll.begin(); value!=ll.end();)
if(*value==key){value=ll.erase(value);}
else value++;
cout<<"updated link list is "<<endl;
for (int val : ll)
    cout << val << "->";
    cout<<"NULL";
}
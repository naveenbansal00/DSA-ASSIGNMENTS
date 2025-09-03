#include<iostream>
#include<stack>
#include <vector>
#include <algorithm>
using namespace std ;
int main (){
vector<int> a = {8,1,3,4};
 vector<int> A = a;  int k=0;
sort(A.begin(),A.end());
vector<int> b ;
stack<int> s ;
for(int i=0;i<a.size();i++){
    s.push(a[i]);
    while(!s.empty() && s.top()==A[k])
    {b.push_back(s.top());s.pop();k++;}

}
if (b == A) {
        cout << "YES, the array can be sorted using a stack.\n";
    } else {
        cout << "NO, the array cannot be sorted using a stack.\n";
    }
for(int i=0;i<b.size();i++){
    cout<<b[i]<<" ";
   
}

 cout<<endl;
 
}
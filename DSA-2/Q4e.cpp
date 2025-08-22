#include<iostream>
using namespace std ;
string lowercase(string s){
int n =s.length() ;
for(int i=0; i<n; i++){
if(s[i]>=65 && s[i]<=90){s[i]+=32;}
} return s ;
}

int main () {
cout<< lowercase("ABCDe");
}
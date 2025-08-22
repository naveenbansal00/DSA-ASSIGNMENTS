#include<iostream>
using namespace std ;

string sorting(string s) {
int n= s.length();
for(int i=0;i<n;i++){
for( int j=0;j<n-1;j++){
    if(tolower(s[j])>tolower(s[j+1])){  
        int temp= s[j];
        s[j]=s[j+1];
        s[j+1]=temp;  }
}} return s;
}
int main () {cout<< sorting("bcda"); }

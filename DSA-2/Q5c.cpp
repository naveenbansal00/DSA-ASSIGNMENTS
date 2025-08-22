#include<iostream>
using namespace std ;
int main () {
int n ;
cout<<"Enter the size of matrix"<<endl;
cin>> n ;
int s = n*(n+1)/2 ;  
int a[s];
cout<<"Enter elements in matrix"<<endl;
for(int i=0;i<s;i++){
 cin>> a[i] ;
}
int k=0;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
           if(i>=j){cout<<a[k]; k++;} // lower triangular matrix 
           else{ cout<<0;}
           cout<<" ";

} cout<<endl;
}
}
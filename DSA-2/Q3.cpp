#include<iostream>
using namespace std ;
void missing_number(int a[],int n){
for(int i=0;i<n;i++){
if(a[i]!=i+1){
cout<<"missing number is "<< i+1 ;
}}}
int main () {int a[]={1,2,3,4,6};
int n= sizeof(a)/sizeof(a[0]);
missing_number(a,n);}
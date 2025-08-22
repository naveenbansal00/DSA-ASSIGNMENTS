#include<iostream>
using namespace std ;
int main (){
int n ;
cout<<"Enter size of diagonal matrix"<<endl;
cin>> n ;
int a[n];
cout<<" Enter element in matrix "<<endl;
for(int i=0;i<n;i++){
cin>> a[i];}
cout<< " Diagonal matrix"<<endl;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
          if(i==j){cout<< a[i];} 
           else {cout<< 0 ;}
           cout<<" ";
        
        
        }cout<<endl;}
          return 0;

}
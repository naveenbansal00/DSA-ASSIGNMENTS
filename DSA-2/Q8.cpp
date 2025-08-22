#include<iostream>
using namespace std ;
int main () {
int a[] = {4,5,9,5,4,0,7};
int n= 7;
int count =0 ;
for(int i=0; i<n;i++){
    bool distinct =false;
     for(int j=0;j<i;j++){
           if(a[i]==a[j] ) { distinct= true ;break;} 
        
}
if(!distinct){count++;}
}
cout<<"Number of distinct element :  "<< count<<endl ;
}
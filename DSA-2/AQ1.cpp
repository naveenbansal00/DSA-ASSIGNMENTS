#include<iostream>
using namespace std ;
int main () {
int arr[] = { 1,4,1,4,5} , k = 3 ;
int n=5;
int count=0;
for(int i=0;i<n;i++){
    for(int j=i; j<n;j++) {
            if(abs(arr[i]-arr[j])== k )
            { count++; cout<<arr[i]<<" "<<arr[j]<<endl;}

    }
}
 cout<<"Number of pair :"<< count <<endl ;


}
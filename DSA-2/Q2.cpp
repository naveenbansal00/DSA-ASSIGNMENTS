#include<iostream>
using namespace std ;
int main () {
int a[]={64,34,25,12,22,11,90};
int n= sizeof(a)/sizeof(a[0]);
for(int i=0;i<n-1;i++){
    bool swapped = false;
for(int j=0;j<n-1-i;j++){

    if(a[j]>a[j+1]){
        int temp= a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
        swapped = true;
    }}if (!swapped)
            break;} 
    
    for(int i=0;i<n;i++)
    cout<< a[i]<<" ";
    
    
    
    
    return 0;
}
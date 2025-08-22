#include<iostream>
using namespace std ;
int main () {
int a[] ={2,4,1,3};
int n = 4 ;
int count =0;
for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        if(i<j && a[i]>a[j]) { count++;}
}
}
cout<<"pair of inversion is/are  "<<count<<endl;

}
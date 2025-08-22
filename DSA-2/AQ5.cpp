#include<iostream>
using namespace std ;
void duplicatetwos(vector<int> &a,vector<int> &b) {
int n = a.size();
int j =0;
for(int i=0;i<n && j<n;i++) {
if(a[i]!=2){b[j]=a[i];j++;}
else {b[j]=a[i];j++; if(j<n){b[j]=2;}j++;}}

}
int main (){
    vector<int> a ={2,3,2};
    vector<int> b ={0,0,0};
    duplicatetwos(a,b);
    for(int k=0;k<b.size();k++){ cout<< b[k]<<endl;}
}
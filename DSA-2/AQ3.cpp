#include<iostream>
using namespace std ;
string sorting(string s) {
int n= s.length();
for(int i=0;i<n;i++){
for( int j=0;j<n-1;j++){
    if(s[j]>s[j+1]){  
        int temp= s[j];
        s[j]=s[j+1];
        s[j+1]=temp;  }
}} return s;
}
int Anagram(string str1 , string str2){
    if(str1.length() !=str2.length()) return 0;
    if(sorting(str1) == sorting(str2)) return 1 ;
    return 0;
}
int main () {

cout<<Anagram("care" , "race")<<endl;

}
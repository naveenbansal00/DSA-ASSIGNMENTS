#include<iostream>
using namespace std ;
string Delete(string a, int pos) {
    a.erase(pos, 1);     // removes 1 char at position pos
    return a;
}

string Delete_vowel(string s){
int n =s.length();
for(int i=0;i<n;i++){
if(tolower(s[i])=='a'||tolower(s[i])=='e'||tolower(s[i])=='i'||tolower(s[i])=='o'||tolower(s[i])=='u') {
s=Delete(s,i); i--;
}} return s;}
int main () {
cout<<Delete_vowel("naveen");
}
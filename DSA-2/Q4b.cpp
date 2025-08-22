#include<iostream>
using namespace std ;


void reverse_string(string str) {
int st = 0;
int end =str.length()-1 ;
while(st<end) swap(str[st++],str[end--]);
cout<< str ;
}
int main () {
    reverse_string("abc ");
return 0;
}
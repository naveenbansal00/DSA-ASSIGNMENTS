#include<iostream>
#include<string>
#include<stack>
using namespace std ;
bool isvalid(string str){
    int n= str.length();
    stack<char> st ;
    for(int i=0; i<n; i++){
        if(str[i] == '(' || str[i] =='{' || str[i] == '[') { st.push(str[i]);}

        else {  if(st.size() == 0) { return false; }
            
            
                     if( str[i]== ')' && st.top()=='(' ||
                         str[i]== ']' && st.top()=='[' ||
                         str[i]== '}' && st.top()=='{' 
){st.pop();}
                     else {return false ; } }

    }


return st.size() == 0 ;

}
int main () {

  cout<<isvalid("(()})")<<endl;
}
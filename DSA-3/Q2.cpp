#include<iostream>
#include<stack>
#include<string>
using namespace std ;
void  reverse_string(string str ){
    stack<char> st ;
    int n = str.length();
    for(int i=0;i<n;i++){
        st.push(str[i]);
    }
    while(!st.empty()){
        cout<< st.top();
        st.pop();
    }
    
}

int main (){

    reverse_string("abcdefgh"); 
    cout<<endl;
}
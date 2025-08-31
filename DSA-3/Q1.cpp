#include<iostream>
#include<vector>
using namespace std ;
class Stack {
    public :
    int v[5] ;
    int top =-1;

            bool isempty (){
            return top == -1;}  

            bool isfull (){
            return  top == 4 ;}

            void push(int value){
            if(isfull()){
            cout<<"stack is full can not put more value"<<endl;}
            else { v[++top]=value;}} 

            void pop(){  
            if(isempty()) {
            cout<<"stack is empty"<<endl;}
            else top--;}
                                    
            void peek (){
            if(isempty()){cout<<"stack is empty"<<endl;}
            else{cout<<v[top]<<endl;} }

            void display (){
            if(isempty()){ cout<<" stack is empty"<<endl; }
            else { for(int i= top ; i >=0; i--){
            cout<<v[i]<<endl;}}}
            };
                
int main(){
 Stack s;
 s.push(10);
 s.push(20);
 s.push(30);
 s.display();
 s.pop();
 s.display(); }


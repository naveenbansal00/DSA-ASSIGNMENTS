#include<iostream>
#include<stack>
using namespace std ;
class Specialstack {
    stack<int> st;
    stack<int> gt;
    public:
    void push(int x){
    st.push(x);
    if (gt.empty() || x <= gt.top()) {
            gt.push(x); }  }
    

     int getMin() {
        if (gt.empty()) {
            return -1;
        }
        return gt.top();
    }
};

int main (){
    Specialstack Stack ;
    Stack.push(8);
    Stack.push(5);
    Stack.push(6);
    Stack.push(2);
    Stack.push(9);
    cout<<Stack.getMin()<<endl;
 
}
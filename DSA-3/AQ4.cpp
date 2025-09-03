#include<iostream>
using namespace std ;
 void dailyTemperatures(vector<int>& a , int n, vector<int> &ans) {
    stack<int> st; 
    for (int i = n-1; i >=0; i--) {
    while (!st.empty() && a[st.top()] <= a[i]) {
    st.pop();}
    if (st.empty()) 
    ans[i] = 0;  
    else 
    ans[i] =st.top()-i;
    st.push(i); }
    for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";}
    cout << endl;
}
int main (){
     vector<int> a = {73,74,75,71,69,72,76,73};
    int n =a.size();
    vector<int> ans(n, 0);
    dailyTemperatures(a,n,ans);
}
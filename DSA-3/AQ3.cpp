#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void nextgreater(vector<int> &a, int n, vector<int> &ans) {
    stack<int> st; 
    

    for (int i = n-1; i >=0; i--) {

          while (!st.empty() && st.top() <= a[i]) {
    st.pop();
}

         
           
        if (st.empty()) 
            ans[i] = -1;  
        else 
            ans[i] =st.top();

        st.push(a[i]); 
    }

    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> a = {6,8,0,1,3};
    int n =a.size();
    vector<int> ans(n, 0);
    nextgreater(a, n, ans);
}

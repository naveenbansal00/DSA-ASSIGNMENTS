#include<iostream>
#include<stack>
using namespace std;

void prevsmaller(int a[], int n, int g[]) {
    stack<int> st; 

    for (int i = 0; i < n; i++) {

    
        while (!st.empty() && st.top() >= a[i]) {
            st.pop();
        }

        if (st.empty()) 
            g[i] = -1;  // no smaller element
        else 
            g[i] = st.top(); // nearest smaller

        st.push(a[i]); // push current element
    }

    
    for (int i = 0; i < n; i++) {
        cout << g[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {4, 5, 2, 10, 8};
    int n = 5;
    int g[n];
    prevsmaller(a, n, g);
}

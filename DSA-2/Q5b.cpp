#include<iostream>
using namespace std ;
int main (){
int n ;
cout<<"enter size of matrix"<<endl;
cin>> n;
int s = 3*n-2 ;
int a[s];
cout<<"enter elements in marix "<<endl ;
for (int i=0;i<s;i++){
    cin>>a[i];
}
int k=0;
cout<< " Tri Diagonal matrix"<<endl;
  for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) { 
                cout << a[k] << " "; k++;  // main diagonal
            }
            else if (i == j + 1) { 
                cout << a[k] << " ";    k++;   // lower diagonal
            }
            else if (i == j - 1) { 
                cout << a[k] << " "; k++;// upper diagonal
            }
            else {
                cout << 0 << " "; // other elements
            }
        }
        cout << endl;
    }

          return 0; 

}
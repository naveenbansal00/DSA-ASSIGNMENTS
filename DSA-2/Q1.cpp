#include<iostream>
using namespace std;

int main () {
    int arr[] = {1,2,3,4};
    int st = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    int end =n-1;
    int tar = 3;
    int result = -1;
while(st<=end){
 int mid = (end-st)/2 + st ;
 if(tar<arr[mid]){
    end=mid-1;
 }
else if (tar>arr[mid]){
    st=mid+1;
}
else { result=mid;
    break;
}

}
  if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

} 

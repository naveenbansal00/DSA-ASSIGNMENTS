#include<iostream>
#include<vector>

using namespace std ;
class Node{
public:
int data ;
Node* left ;
Node* right ;
Node(int val){
    data = val ;
    left = right = NULL;}
};
    static int idx = -1;
Node* buildtree(vector<int> preorder){
    idx++;
    if(preorder[idx]== -1){
    return NULL ;}
    Node* root = new Node(preorder[idx]);
    root->left =buildtree(preorder);
    root->right =buildtree(preorder);
return root ;}

bool isBSThelper(Node* root, long long minVal, long long maxVal) {
    if (root == NULL) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBSThelper(root->left, minVal, root->data) &&
    isBSThelper(root->right, root->data, maxVal);
    }

  
bool isBST(Node* root){
    return isBSThelper(root, LLONG_MIN, LLONG_MAX);}

int main(){
vector<int> preorder = {4, 2, 1, -1, -1, 3, -1, -1, 6, 5, -1, -1, 7, -1, -1};

Node* root =buildtree(preorder);
 if (isBST(root))
        cout << "Tree is a BST" << endl;
    else
        cout << "Tree is NOT a BST" << endl;


return 0 ;}



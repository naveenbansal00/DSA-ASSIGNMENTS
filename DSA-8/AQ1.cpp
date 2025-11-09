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

int sumOfLeftLeaves(Node* root){
    if(root==NULL){
    return 0 ;}
    if(root->left==NULL && root->right==NULL){
    return 0;}
    int total = 0;
    if (root->left && root->left->left==NULL && root->left->right==NULL)
    total += root->left->data;
    total += sumOfLeftLeaves(root->left);
    total += sumOfLeftLeaves(root->right);
    return total;}

int main(){
vector<int> preorder = {1, 2, -1,-1,3,4,-1,-1,5,-1,-1 };
Node* root =buildtree(preorder);
return 0 ;}
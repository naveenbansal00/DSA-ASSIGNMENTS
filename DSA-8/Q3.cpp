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


Node* insert(Node* root,int value){
    if(root==NULL){
    return new Node(value);}
    if(value <root->data){
    root->left = insert(root->left,value);}
    else{
    root->right = insert(root->right,value);}
    return root ;
}
Node* buildBST(vector<int> arr){
    Node* root =NULL ;
    for(int val : arr){
    root = insert(root,val);}
    return root ;}

int Maxdepth(Node* root){
    if(root==NULL){
    return 0 ;}
    int leftHT = Maxdepth(root->left);
    int rightHT = Maxdepth(root->right);
    return max(leftHT,rightHT ) + 1 ;}

int Mindepth(Node* root) {
    if (root==NULL) return 0;                       
    if (root->left ==NULL&& root->right==NULL) return 1; 
    if (!root->left) return 1 + Mindepth(root->right);  
    if (!root->right) return 1 + Mindepth(root->left);  
    return 1 + min(Mindepth(root->left), Mindepth(root->right));
}

Node* getinordersuccessor(Node* root){  // left most node in right subtree
    while(root!=NULL && root->left!=NULL){
    root=root->left;}
    return root ;}

Node* DelNode(Node* root , int key){
    if(root==NULL){
    return NULL;}
    if(key<root->data){
    root->left = DelNode(root->left,key);}
    else if(root->data<key)
    {root->right = DelNode(root->right,key);}
    else{ // key == root ka data
    if(root->left==NULL){
    Node* temp = root->right;
    delete root ;
    return temp ;}
    else if (root->right==NULL){
    Node* temp = root->left ;
    delete root ;
    return temp ;}
    else{
    Node* IS = getinordersuccessor(root->right);
    root->data = IS->data;
    DelNode(root->right,IS->data);}}
    return root ;}

int main (){
vector<int> arr = {3,2,1,5,6,4};
Node* root = buildBST(arr);
}
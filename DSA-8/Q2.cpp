#include<iostream>
#include<vector>
#include<queue>
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

void inOrder (Node* root){ 
    if (root == NULL) {
    return;}
    inOrder (root->left);
    cout << root->data <<" ";
    inOrder(root->right);}

bool serch (Node* root ,int key ){
    if(root == NULL){
    return false ;} 
    if(root->data ==key){
    return true;}
    if(key<root->data){
    return serch(root->left,key);}
    else{
    return serch(root->right,key);}}

Node* getinordersuccessor(Node* root){  // left most node in right subtree
    while(root!=NULL && root->left!=NULL){
    root=root->left;}
    return root ;}

Node* getinorderpredecssor(Node* root){  // right most node in left subtree
    while(root!=NULL && root->right!=NULL){
    root=root->right;}
    return root ;}
    
Node* Maxelement(Node* root){
    if(root==NULL){
    return NULL;}
    Node* temp =root ;
    while(temp!=NULL && temp->right!=NULL){
    temp=temp->right;
     } return temp; }

Node* Minelement(Node* root){
    if(root==NULL){
    return NULL;}
    Node* temp =root ;
    while(temp!=NULL && temp->left!=NULL){
    temp=temp->left;}  
    return temp; }


 



int main (){
vector<int> arr = {3,2,1,5,6,4};
Node* root = buildBST(arr);
inOrder(root);
}
#include<iostream>
#include<vector>
#include<map>
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
    static int idx = -1;
Node* buildtree(vector<int> preorder){
    idx++;
    if(preorder[idx]== -1){
    return NULL ;}
    Node* root = new Node(preorder[idx]);
    root->left =buildtree(preorder);
    root->right =buildtree(preorder);
return root ;}


vector<int> rightview(Node* root) {
    vector<int> view;
    if (root == NULL) return view;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
    int n = q.size(); 
    for (int i = 0; i < n; i++) {
    Node* curr = q.front();
    q.pop();
   if (i == n-1)// last node of this level -> part of right view
    view.push_back(curr->data);
    if (curr->left)
    q.push(curr->left);
    if (curr->right)
    q.push(curr->right); }}
    return view;}

int main(){
vector<int> preorder = {1, 2, -1,-1,3,4,-1,-1,5,-1,-1 };
Node* root =buildtree(preorder);
vector<int> ans = rightview(root);
for(auto it : ans ){
cout<<it;}
return 0 ;}
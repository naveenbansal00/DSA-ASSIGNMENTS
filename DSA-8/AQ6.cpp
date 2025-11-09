#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd,
                      vector<int>& postorder, int postStart, int postEnd,
                      unordered_map<int, int>& inMap) {
    if (inStart > inEnd || postStart > postEnd) return NULL;

    Node* root = new Node(postorder[postEnd]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTreeHelper(inorder, inStart, inRoot - 1,
                                 postorder, postStart, postStart + numsLeft - 1, inMap);

    root->right = buildTreeHelper(inorder, inRoot + 1, inEnd,
                                  postorder, postStart + numsLeft, postEnd - 1, inMap);

    return root;
}

Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++)
        inMap[inorder[i]] = i;

    return buildTreeHelper(inorder, 0, inorder.size() - 1,
                           postorder, 0, postorder.size() - 1, inMap);
}

void printPreorder(Node* root) {
    if (root==NULL) return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Node* root = buildTree(inorder, postorder);
    printPreorder(root);
}

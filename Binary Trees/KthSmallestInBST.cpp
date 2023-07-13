#include<bits/stdc++.h>
using namespace std;


//tree data structure
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    //constructor function for the node
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void kTHSmallestInBST(Node* root, int k, int& ans, int& count){
    if(root == NULL) return;
    kTHSmallestInBST(root->left,k,ans,count);
    if(++count == k){
        ans = root -> data;
        return;
    }
    kTHSmallestInBST(root->right,k,ans,count);
}


int main()
{
    // Binary search tree
        /*
            4
          /   \
        2       7
      /   \    /  \
     1     3  5    8
    */
    Node *root = new Node(4);

    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(8);

    int count = 0, ans = 0, k = 4;
    kTHSmallestInBST(root,k,ans,count);
    cout<<"Kth Smallest in BST: " << ans;
    return 0;
}

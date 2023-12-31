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

Node* solve(Node* root, int p, int q){
    if(!root) return NULL;
    else if ( (root->data >= p && root -> data <= q) || (root->data >= q && root -> data <= p) ) return root;
    else if ( root -> data > p && root -> data > q) return solve(root->left,p,q);
    else if ( root -> data < p && root -> data < q) return solve(root->right,p,q);
    return NULL;
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
    cout<<"LCA in BST: " << solve(root,8,5)->data;
    return 0;
}

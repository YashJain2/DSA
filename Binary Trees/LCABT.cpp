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

Node* lca(Node* root, int p, int q){
    if(root == NULL || root->data == p || root->data == q) return root;
    Node* left = lca(root->left,p,q);
    Node* right = lca(root->right,p,q);
    if(left == NULL) return right;
    if(right == NULL) return left;
    return root;
}


int main()
{
    // Binary tree
        /*
            1
          /   \
        2       3
      /   \    /  \
     4     5  6    7
    */
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<"LCA: "<<lca(root,6,5)->data;
    return 0;
}
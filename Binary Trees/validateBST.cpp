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

bool validateBST(Node* root, long int max, long int min){
    if(root == NULL) return true;
    if(root->data >= max || root->data <= min) return false;
    return validateBST(root->left, root->data, min) && validateBST(root->right, max, root->data);
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

    cout<<"Is BST: " << validateBST(root,LONG_MIN,LONG_MAX);
    return 0;
}

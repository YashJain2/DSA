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

//min depth of the binary tree
// distance of the root node down to the nearest leaf node
int minDepth(Node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == root->right == NULL){
        return 1;
    }
    //left skew tree
    if(root->left == NULL){
        return 1 + minDepth(root->left);
    }
    //Right skew tree
    if(root->right == NULL){
        return 1 + minDepth(root->right);
    }
    int leftHeight = minDepth(root->left) + 1;
    int rightHeight = minDepth(root->right) + 1;
    return min(leftHeight,rightHeight);
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
    cout<<"Max depth of BT: " << maxDepth(root);
    return 0;
}
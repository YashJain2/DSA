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

//max depth is the height of the binary tree
//distnace between the root node to the farthest leaf node
int maxDepth(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = maxDepth(root->left) + 1;
    int rightHeight = maxDepth(root->right) + 1;
    return max(leftHeight,rightHeight);
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
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

int heightBT(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = 1 + heightBT(root->left);
    int rightHeight = 1 + heightBT(root->right);
    return max(leftHeight,rightHeight);
}



// checking for balanced BT
// tree having abs(leftHeight - rightHeight) <= 1 for every node
bool balancedBT(Node* root){
    if(root == NULL){
        return true;
    }
    int leftHeight = heightBT(root->left);
    int rightHeight = heightBT(root->right);
    if(abs(leftHeight - rightHeight) > 1){
        return false;
    }
    bool leftBanlacedTree = balancedBT(root->left);
    bool rightBalancedTree = balancedBT(root->right);
    return (leftBanlacedTree || rightBalancedTree);
}

// checking for balanced binary tree while finding the depth of it
int balancedBT1(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = 1 + balancedBT1(root->left);
    if(leftHeight == -1){
        return -1;
    }
    int rightHeight = 1 + balancedBT1(root->right);
    if(rightHeight == -1){
        return -1;
    }
    if(abs(leftHeight - rightHeight) > 1){
        return -1;
    }
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
    // root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    cout<<"Is balanced BT: " << balancedBT(root) << endl;
    balancedBT1(root) == -1 ? cout<< "Not a balanced BT\n" : cout<<"Is a balanced BT\n";
    return 0;
}
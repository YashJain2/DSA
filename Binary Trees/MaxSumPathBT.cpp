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

//max sum path in the binary tree
int maxSumPath(Node* root, int& sum){
    if(root == NULL){
        return 0;
    }
    int leftSum = maxSumPath(root->left,sum);
    int rightSum = maxSumPath(root->right,sum);
    sum = max(sum, root->data + leftSum + rightSum);
    return max(leftSum,rightSum) + root -> data;
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
    int sum = 0;
    maxSumPath(root,sum);
    cout<<"Max Sum Path of BT: " << sum;
    return 0;
}
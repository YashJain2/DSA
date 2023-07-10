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


int calcLeftHeight(Node* node){
    int height = 0;
    if(node == NULL) return height;
    while(node){
        node = node->left;
        height++;
    }
    return height;
}

int calcRightHeight(Node* node){
    int height = 0;
    if(node == NULL) return height;
    while(node){
        node = node->right;
        height++;
    }
    return height;
}

int countNodes(Node* root){
    if(root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

//only be used if its complete binary tree
int countNodes1(Node* root){
    if(root == NULL) return 0;
    int lh = calcLeftHeight(root);
    int rh = calcRightHeight(root);
    if(lh == rh) return ((1<< lh) - 1);
    return 1 + countNodes1(root->left) + countNodes1(root->right);
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
    cout<< "Count Nodes: "<< countNodes(root) << endl;
    cout<< "Count Nodes: "<< countNodes1(root) << endl;
    return 0;
}

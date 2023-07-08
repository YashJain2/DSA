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
    int lHeight = 1 + heightBT(root->left);
    int rHeight = 1 + heightBT(root->right);
    return max(lHeight,rHeight);
}

// largest diameter of a binary tree
int diameter(Node* root){
    if(root == NULL){
        return 0;
    }
    int lHeight = heightBT(root->left);
    int rHeight = heightBT(root->right);
    int currDiameter = 1 + lHeight + rHeight;
    int lDiameter = diameter(root->left);
    int rDiameter = diameter(root->right);
    return max(currDiameter,max(lDiameter,rDiameter));
}

// optimised approach of binary tree
int diameter1(Node* root, int& mx){
    if(root == NULL){
        return 0;
    }
    int left = diameter1(root->left, mx);
    int right = diameter1(root->right, mx);
    mx = max(mx, 1 + left + right);
    return 1 + max(left,right);
}

int main(){
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
    int mx = INT_MIN;
    diameter1(root,mx);
    cout<<mx;
    cout<<endl;
    cout<<"Diameter: " << diameter(root) << endl;
    return 0;
}
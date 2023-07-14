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


Node* solve(vector<int> preorder, int& i, int bound){
    if(i == preorder.size() || preorder[i] > bound ) return NULL;
    Node* newNode = new Node(preorder[i++]);
    newNode -> left = solve(preorder,i,newNode->data);
    newNode -> right = solve(preorder,i,bound);
    return newNode;
}

void printInorder(Node* root){
    if(!root) return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
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
    // preorder: 4 2 1 3 7 5 8
    // Node *root = new Node(4);

    // root->left = new Node(2);
    // root->right = new Node(7);
    // root->left->left = new Node(1);
    // root->left->right = new Node(3);
    // root->right->right = new Node(8);
    vector<int> preorder{4,2,1,3,7,5,8};
    int i =0;
    Node* node = solve(preorder, i, INT_MAX);
    printInorder(node);
    return 0;
}

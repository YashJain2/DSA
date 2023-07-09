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

bool solve(Node* p, Node* q){
    if(p == NULL || q == NULL) return (p == q);
    if(p->data != q->data) return false;
    return solve(p->left, q->right) & solve(p->right,q->left);
}


bool isSymmetric(Node* root){
    if(root == NULL) return true;
    return solve(root->left,root->right);
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
    cout<<"Is Symmetric? "<<isSymmetric(root)<<endl;
    return 0;
}
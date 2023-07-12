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

Node* solve(Node* root, int val){
    if(root == NULL) return (new Node(val));
    Node* cur = root;
    while(true){
        if(cuur->data <= val){
            if(cur->right != NULL) cur = cur -> right;
            else{
                cur -> right = new Node(val);
                break;
            }
        }
        else{
            if(cur->left != NULL) cur = cur -> left;
            else{
                cur -> left = new Node(val);
                break;
            }
        }
    }
    return root;
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

    root = solve(root,5);
    return 0;
}

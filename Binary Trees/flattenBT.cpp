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

    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* temp = st.top();
        st.pop();
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
        if(!st.empty()) node->right = st.top();
        node->left = NULL;
    }
    return 0;
}

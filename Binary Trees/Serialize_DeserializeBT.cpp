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

string serialize(Node* root){
    string ans = "";
    if(root == NULL) return ans;
    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node* node = s.top();
        s.pop();
        if(node == NULL) ans.append("X ");
        else ans.append(to_string(node->data) + " ");
        if(node != NULL){
            s.push(node->right);
            s.push(node->left);
        }
    }
    return ans;
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
    cout<<"Serialize a BT: " << serialize(root);
    return 0;
}

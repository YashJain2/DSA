
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

bool solve(Node* root, int p, vector<int>& ans){
    if(root == NULL) return false;
    ans.push_back(root->data);
    if(root->data == p) return true;
    if(solve(root->left,p,ans) || solve(root->right,p,ans)) return true;
    ans.pop_back();
    return false;
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
    vector<int> ans;
    solve(root,6,ans);
    for(auto i: ans){
        cout<<i <<" ";
    }
    return 0;
}
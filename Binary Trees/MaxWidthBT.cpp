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


//Uses the concept of segment tree with level order traversal
/*
             i
          /    \ 
        /       \
     (2*i +1)  (2*i +2)
*/
int maxWidth(Node* root){
    int ans = 0;
    if(root == NULL) return ans;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int size = q.size();
        int idx = q.front().second;
        int first,last;
        for(int i = 0;i<size;i++){
            auto node = q.front();
            int curr = node.second - idx;
            
            q.pop();
            if(node.first->left) q.push({node.first->left,2*curr + 1});
            if(node.first->right) q.push({node.first->right,2*curr + 2});
            if(i == 0) first = curr;
            if(i == (size - 1)) last = curr;
        }
        ans = max(ans,last - first + 1);
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
    root->left->left->left = new Node(10);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);
    cout<<"Max width: "<< maxWidth(root);
    return 0;
}

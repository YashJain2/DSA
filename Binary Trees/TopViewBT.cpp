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

vector<int> topView(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    map<int,int> mp;
    queue<pair<Node* , int>> q; // pair of {node,vertical position}
    q.push({root,0});
    while(!q.empty()){
        auto i = q.front();
        q.pop();
        if(mp.find(i.second) == mp.end()){
            mp[i.second] = i.first->data;
        }
        if(i.first->left) q.push({i.first->left,i.second - 1});
        if(i.first->right) q.push({i.first->right,i.second + 1});
    }
    for(auto i : mp){
        ans.push_back(i.second);
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
    vector<int> ans = topView(root);
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}
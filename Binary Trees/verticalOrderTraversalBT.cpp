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

vector<vector<int>> verticalOrderTraversalInBT(Node* root){
    vector<vector<int>> ans;
    map<int,map<int,multiset<int>>> mp;
    queue<pair<Node* , pair<int,int>>> q; // pair of {node,{vertical position,level}}
    q.push({root,{0,0}});
    while(!q.empty()){
        auto i = q.front();
        q.pop();
        Node* node = i.first;
        int x = i.second.first, y = i.second.second;
        mp[x][y].insert(node->data);
        if(node->left) q.push({node->left,{x-1,y+1}});
        if(node->right) q.push({node->right,{x+1,y+1}});
    }
    for(auto i : mp){
        vector<int> temp;
        for(auto j : i.second){
            temp.insert(temp.end(),j.second.begin(),j.second.end());
        }
        ans.push_back(temp);
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
    vector<vector<int>> ans = verticalOrderTraversalInBT(root);
    for(auto i : ans){
        for(auto j : i){
            cout<< j << " ";
        }
        cout<<endl;
    }
    return 0;
}
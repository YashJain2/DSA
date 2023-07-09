#include<bits/stdc++.h>
using namespace std;
vector<int> ds;

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

vector<int> rightView(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i = 0;i<size;i++){
            if(i == size -1){
                ans.push_back(q.front()->data);
            }
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();
        }
    }
    return ans;
}

void rightView1(Node* root, int level){
    if(root == NULL) return;
    if(ds.size() == level) ds.push_back(root->data);
    rightView1(root->right, level + 1);
    rightView1(root->left, level + 1);
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
    vector<int> ans = rightView(root);
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}
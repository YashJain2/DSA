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
map<Node*,int> levelMap;
    
Node* search(Node* root, int val){
    if(!root) return NULL;
    if(root->data == val) return root;
    Node* left = search(root->left, val);
    Node* right = search(root->right, val);
    if(!left) return right;
    if(!right) return left;
    return NULL;
}
    
void levelOrderTraversal(Node* root){
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    int level = 0;
    levelMap[root] = level;
    while(!q.empty()){
        int size = q.size();
        level++;
        for(int i =0;i<size;i++){
            Node* temp = q.front();
            q.pop();
            levelMap[temp] = level;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}
    
Node* lcaNode(Node* root, Node* a, Node* b){
    if(!root || root == a || root == b) return root;
    Node* left = lcaNode(root->left,a,b);
    Node* right = lcaNode(root->right,a,b);
    if(!left) return right;
    if(!right) return left;
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
    // preorder: 4 2 1 3 7 5 8
    Node *root = new Node(4);

    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(8);
    // vector<int> preorder{4,2,1,3,7,5,8};
    int a = 3, b = 7;
    levelOrderTraversal(root);
    Node* x = search(root,a);
    Node* y = search(root,b);
    Node* lca = lcaNode(root,x,y);
    int d = levelMap[lca];
    int d1 = levelMap[x];
    int d2 = levelMap[y];
    cout << abs(d1-d) + abs(d2-d);
    return 0;
}

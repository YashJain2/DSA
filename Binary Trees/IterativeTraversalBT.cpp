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


//iterative preorder using stack
vector<int> preorder(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* node  = st.top();
        st.pop();
        ans.push_back(node->data);
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
    }
    return ans;
}

//iterative inorder traversal using stack
vector<int> inorder(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    stack<Node*> st;
    while(true){
        while(root){
            st.push(root);
            root = root -> left;
        }
        if(st.empty()){
            return ans;
        }
        else{
            Node* node = st.top();
            st.pop();
            ans.push_back(node->data);
            root = node -> right;
        }
        
    }
    return ans;
}

//iterative postorder using 2 stacks
void postorder(Node* root){
    if(root == NULL){
        return;
    }
    stack<Node*> s1;
    stack<int> s2;
    s1.push(root);
    while(!s1.empty()){
        Node* tempNode = s1.top();
        s2.push(tempNode->data);
        s1.pop();
        if(tempNode->left){
            s1.push(tempNode->left);
        }
        if(tempNode->right){
            s1.push(tempNode->right);
        }
    }
    vector<int> ans;
    while(!s2.empty()){
        ans.push_back(s2.top());
        s2.pop();
    }
    for(auto i: ans){
        cout<<i<<" ";
    }
}

//iterative postorder using single stacks
vector<int> postorder1(Node* root){
   vector<int> postOrderList;
    stack<Node*> st;
    while (true) {
        while (root) {
            st.push(root);
            st.push(root);
            root = root->left;
        }
        if (st.empty())
            return postOrderList;
        root = st.top();
        st.pop();
        if (!st.empty() && st.top() == root)
            root = root->right;
        else {
            postOrderList.push_back(root->data);
            root = NULL;
        }
    }
    return postOrderList;
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
    // postorder(root);
    vector<int> ans = inorder(root);
    for(auto& i: ans){
        cout<<i<<" ";
    }
    return 0;
}
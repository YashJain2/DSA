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
    vector<int> ans = postorder1(root);
    for(auto& i: ans){
        cout<<i<<" ";
    }
    return 0;
}
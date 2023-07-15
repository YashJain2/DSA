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


//pair<pair<int,int>,int> -> {{sum,max},min}
pair<pair<int,int>,int> solve(Node* root, int& sum){
    if(!root) return {{0,INT_MIN},INT_MAX};
    if(!(root->left) && !(root->right)) {
        sum = max(sum,root->data);
        return{{root->data,root->data},root->data};
    }

    auto left = solve(root->left,sum);
    auto right = solve(root->right,sum);

    if(root->data > left.first.second && root->data < right.second){
        int temp = root -> data + left.first.first + right.first.first;
        sum = max(sum,temp);
        return {{temp,max(root->data,right.first.second)},min(root->data,left.second)};
    }
    return{{max(left.first.first,right.first.first),INT_MAX},INT_MIN};
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
    int ans = 0;
    solve(root,ans);
    cout<<"Max Sum BST: "<< ans << endl;
    return 0;
}

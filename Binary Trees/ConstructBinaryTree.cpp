#include<bits/stdc++.h>
using namespace std;

//tree data structure
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    //constructor function for the node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int search(int* inorder, int key, int start, int end){
    for(int i = start;i<=end;i++){
        if(key == inorder[i]){
            return i;
        }
    }
    return -1;
}

// Preorder traversal: 1 2 4 5 3 6 7 
// Inorder traversal: 4 2 5 1 6 3 7 
//Construct a binary tree using preorder and inorder arrays
Node* preorderInorderBinaryTree(int* preorder, int* inorder, int start, int end){
    static int index = 0;
    if(start>end && index > 6){
        return NULL;
    }
    Node* node = new Node(preorder[index]);
    int position = search(inorder,preorder[index],start,end);
    index++;
    if(start == end){
        return node;
    }
    node -> left = preorderInorderBinaryTree(preorder,inorder,start,position - 1);
    node -> right = preorderInorderBinaryTree(preorder,inorder,position + 1, end);
    return node;
}

// Postorder traversal: 4 5 2 6 7 3 1 
// Inorder traversal: 4 2 5 1 6 3 7 
//Construct a binary tree using preorder and inorder arrays
Node* postorderInorderBinaryTree(int* postorder, int* inorder, int start, int end){
    static int index = 6; // num of nodes in binary tree
    if(start>end){
        return NULL;
    }
    Node* node = new Node(postorder[index]);
    int position = search(inorder,postorder[index],start,end);
    index--;
    if(start == end){
        return node;
    }
    node -> right = postorderInorderBinaryTree(postorder,inorder,position + 1, end);
    node -> left = postorderInorderBinaryTree(postorder,inorder,start,position - 1);
    return node;
}

//Inorder traversal in binary tree
void inorderPrint(Node* root){
    if(root == NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

// Preorder traversal in Binary Tree
void preorderPrint(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

// Postorder traversal in Binary Tree
void postorderPrint(Node* root){
    if(root == NULL){
        return;
    }
    postorderPrint(root->left);
    postorderPrint(root->right);
    cout<<root->data<<" ";
}

int main(){
    int preorder[] = {1,2,4,5,3,6,7};
    int inorder[] = {4,2,5,1,6,3,7};
    int postorder[] = {4,5,2,6,7,3,1};
    int start = 0;
    int end = 6;
    Node* newNode = preorderInorderBinaryTree(preorder,inorder,start,end);
    cout<<"Preorder traversal: "; preorderPrint(newNode); cout<<endl;
    cout<<"Inorder traversal: "; inorderPrint(newNode); cout<<endl;
    Node* newNode1 = postorderInorderBinaryTree(postorder,inorder,start,end);
    cout<<"Postorder traversal: "; postorderPrint(newNode1); cout<<endl;
    cout<<"Inorder traversal: "; inorderPrint(newNode1); cout<<endl;
    return 0;
}
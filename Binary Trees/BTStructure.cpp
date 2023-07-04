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

// Preorder traversal in Binary Tree
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//Inorder traversal in Binary Tree
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//Postorder traversal in Binary Tree
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//Level order traversal in Binary Tress
void levelOrder(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> tempQ;
    tempQ.push(root);
    while(!tempQ.empty()){
        Node* tempNode = tempQ.front();
        tempQ.pop();
        cout<<tempNode->data<<" ";
        if(tempNode->left){
            tempQ.push(tempNode->left);
        }
        if(tempNode->right){
            tempQ.push(tempNode->right);
        }
    }
}

// kth level sum of the binary tree
int KTHLevelSum(Node* root, int k){
    int ans = 0;
    if(root == NULL){
        return ans;
    }
    queue<Node*> tempQ;
    tempQ.push(root);
    while(!tempQ.empty() && (k > 0)){
        ans = 0;
        int size = tempQ.size();
        for(int i = 0;i<size;i++){
            Node* tempNode = tempQ.front();
            tempQ.pop();
            ans += tempNode -> data;
            if(tempNode->left){
                tempQ.push(tempNode->left);
            }
            if(tempNode->right){
                tempQ.push(tempNode->right);
            }
        }
        k--;
    }
    if(k > 0){
        cout<<"Sorry tree is small\n";
        return -1;
    }
    return ans;
}

//Left view of binary tree
void leftView(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> tempQ;
    tempQ.push(root);
    while(!tempQ.empty()){
        int size = tempQ.size();
        // cout<<size<<endl;
        for(int i = 0;i<size;i++){
            Node* tempNode = tempQ.front();
            tempQ.pop();
            if(i == 0){
                cout<<tempNode->data<<" ";
            }
            if(tempNode->left){
                tempQ.push(tempNode->left);
            }
            if(tempNode->right){
                tempQ.push(tempNode->right);
            }
        }
    }
}

//Right view of binary tree
void rightView(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> tempQ;
    tempQ.push(root);
    while(!tempQ.empty()){
        int size = tempQ.size();
        for(int i = 0;i<size;i++){
            Node* tempNode = tempQ.front();
            tempQ.pop();
            if(i == (size - 1)){
                cout<<tempNode->data<<" ";
            }
            if(tempNode->left){
                tempQ.push(tempNode->left);
            }
            if(tempNode->right){
                tempQ.push(tempNode->right);
            }
        }
    }
}

//Nodes in a binary tree
int countNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

//Height of a binary tree
int heightBT(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = 1 + heightBT(root->left);
    int rightHeight = 1 + heightBT(root->right);
    return max(leftHeight,rightHeight);
}

//Sum of binary Tree
int sumBT(Node* root){
    if(root == NULL){
        return 0;
    }
    return root->data + sumBT(root->left) + sumBT(root->right);
}

//diameter of binary tree
// We have to consider two cases
//Case-I: node is present in the diamter
//Case-II: Diameter is consisting only of left subtree or right subtree
int diameterBT(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = heightBT(root->left);
    int rightHeight = heightBT(root->right);

    int currDiameter = 1 + leftHeight + rightHeight;

    int leftDiameter = diameterBT(root->left);
    int rightDiameter = diameterBT(root->right);
    return max(currDiameter,max(leftDiameter,rightDiameter));
}


int optimisedDiameterBT(Node* root, int* height){
    
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
    
    cout<<"Preorder traversal: "; preorder(root); cout<<"\n";
    cout<<"Inorder traversal: "; inorder(root); cout<<"\n";
    cout<<"Postorder traversal: "; postorder(root); cout<<"\n";
    cout<<"LevelOrder traversal: "; levelOrder(root); cout<<"\n";
    cout<<"Left view: "; leftView(root); cout<<"\n";
    cout<<"Right view: "; rightView(root); cout<<"\n";
    cout<<"Kth Level Sum of Binary Tree: " << KTHLevelSum(root,3) << endl;
    cout<<"Nodes in a binary tree: " << countNodes(root) << endl;
    cout<<"Height of a binary tree: "<< heightBT(root) << endl;
    cout<<"Sum of a binary tree: " << sumBT(root) << endl;
    cout<<"Diameter of a binary tree: " << diameterBT(root) << endl;
    return 0;
}
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

void make_parent(Node* root, unordered_map<Node*,Node*>& parent){
       queue <Node*> q; q.push(root);
        while(!q.empty()){
            Node * currNode = q.front();
            q.pop();
            if(currNode->left) parent[currNode->left] = currNode, q.push(currNode->left);
            if(currNode->right) parent[currNode->right] = currNode, q.push(currNode->right);
        }
    }

    bool search(Node* root, int target, Node*& temp){
        if(root == NULL) return false;
        if(root->data == target){
            temp = root;
            return true;
        }
        bool x = search(root->left,target, temp);
        bool y = search(root->right,target, temp);
        return x || y;
    }

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        vector<int> ans;
        if(root == NULL) return ans;
        
        Node* targetNode = NULL;
        bool nodeInTree = search(root,target,targetNode);
        if(!nodeInTree) return ans;
        
        unordered_map<Node*,Node*> parent;
        make_parent(root,parent);

        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        int curr_level = 0;
        while(!q.empty()){
            int size = q.size();
            if(curr_level++ == k) break;
            for(int i =0;i<size;i++){                
                Node* tempNode = q.front();
                q.pop();
                if(tempNode->left && !visited[tempNode->left]){
                   q.push(tempNode->left);
                    visited[tempNode->left] = true;
                }
                if(tempNode->right && !visited[tempNode->right]){
                    q.push(tempNode->right);
                    visited[tempNode->right] = true;
                }
                if(parent[tempNode] && !visited[parent[tempNode]]){
                    q.push(parent[tempNode]);
                    visited[parent[tempNode]] = true;
                }    
            }
        }
        while(!q.empty()){
            Node* tempNode = q.front();
            q.pop();
            ans.push_back(tempNode->data);
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
    vector<int> ans = KDistanceNodes(root, 7, 4);
    for(auto i: ans){
        cout<< i<< " ";
    }
    return 0;
}

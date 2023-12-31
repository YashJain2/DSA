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

class TreeAncestor {
    vector<vector<int> > P; // P[i][node] :::: [node] 's [2^i]th parent
    
public:
    TreeAncestor(int n, vector<int>& parent) {
       // initialize
        P.resize(20, vector<int>(parent.size(), -1));
        
        // 2^0
        for(int i = 0; i < parent.size(); i++){
            P[0][i] = parent[i];
        }
        
        // 2^i using binary lifting
        for(int i = 1; i < 20; i++){
            for(int node = 0; node < parent.size(); node ++){
                int nodep = P[i-1][node];
                if(nodep != -1) P[i][node] = P[i-1][nodep];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0; i < 20; i++){
            if(k & (1 << i)){
                node = P[i][node];
                if(node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

int main()
{
    return 0;
}

// Question Link: https://practice.geeksforgeeks.org/problems/burning-tree/1/#

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  
  private:
    unordered_map<Node*,Node*> parentMapProvider(Node* root) {
        unordered_map<Node*,Node*> parent;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* topN = q.front();
            q.pop();
            if(topN->left) {
                q.push(topN->left);
                parent[topN->left] = topN;
            }
            if(topN->right) {
                q.push(topN->right);
                parent[topN->right] = topN;
            }
        }
        return parent;
    }
  
    Node* nodeProviderFromValue(Node* root, int target) {
        if(root == NULL) return NULL;
        if(root->data == target) return root;
        Node* left = nodeProviderFromValue(root->left,target);
        if(left!=NULL) return left;
        Node* right = nodeProviderFromValue(root->right,target);
        return right;
    }
    
    int bfs(Node* targetNode, unordered_map<Node*,Node*>& parentMap) {
        cout<<"3s"<<endl;
        unordered_set<Node*> doneNodes;
        queue<Node*> q;
        int count = 0;
        q.push(targetNode);
        doneNodes.insert(targetNode);
        while(!q.empty()) {
            count++;
            int n = q.size();
            for(int i=0; i<n; i++) {
                Node* topNode = q.front();
                q.pop();   
                if(topNode->left!=NULL && doneNodes.find(topNode->left)==doneNodes.end()) {
                    q.push(topNode->left);
                    doneNodes.insert(topNode->left);
                }
                if(topNode->right!=NULL && doneNodes.find(topNode->right)==doneNodes.end()) {
                    q.push(topNode->right);
                    doneNodes.insert(topNode->right);
                }
                if(parentMap[topNode] && doneNodes.find(parentMap[topNode])==doneNodes.end()) {
                    q.push(parentMap[topNode]);
                    doneNodes.insert(parentMap[topNode]);
                }
            }
        }
        cout<<"3e"<<endl;
        return count-1;
    }
  
  public:
    int minTime(Node* root, int target) {
        // Your code goes here
        cout<<"1s"<<endl;
        unordered_map<Node*,Node*> parentMap = parentMapProvider(root);
        cout<<"1e"<<endl;
        cout<<"2s"<<endl;
        Node* targetNode = nodeProviderFromValue(root, target);
        cout<<"2e"<<endl;
        return bfs(targetNode,parentMap);
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    // scanf("%d ", &tc);
    tc = 1;
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends
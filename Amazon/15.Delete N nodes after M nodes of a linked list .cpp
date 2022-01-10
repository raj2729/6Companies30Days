// Question Link: https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1/#

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here   
        Node* current = head;
        while(true) {
            int val = M-1;
            while(current!=NULL && val--) {
                current = current->next;
            }
            if(current==NULL) return;
            Node* connectingNode = current;
            val = N+1;
            while(current!=NULL && val--) {
                current = current->next;
            }
            if(current==NULL) {
                connectingNode->next = NULL;
                return;
            }
            connectingNode->next = current;
        }
    }
};



// Find max 10 numbers in a list having 10M entries.

// Its better to maintain an array of of size 10, O(10) constant operations will happen.
// because though this solution will do work in O(log10), because of constant factor of priority queue, overall pq might be slower.

// But here is a pq solution which is more generalized

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> values(n);
    for(int i=0; i<n; i++)  
        cin>>values[i];
    priority_queue<int,vector<int>,greater<int>> pq; // Min Heap
    for(int i=0; i<n; i++) {
        int val = values[i];
        if(pq.size()<10) {
            pq.push(val);
        } else {
            int top = pq.top();
            if(val>top) {
                pq.pop();
                pq.push(val);
            }
        }
    }
    while(pq.size()!=0) {
        cout<<pq.top()<<endl;
        pq.pop();
    }
}


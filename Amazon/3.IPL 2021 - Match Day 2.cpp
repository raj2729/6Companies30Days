// Question Link: https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<k-1; i++) {
            pq.push({arr[i],i});
        }
        int start = 0;
        int end = k-1;
        while(end<n) {
            pq.push({arr[end],end});
            int topInd = pq.top().second;
            while(topInd < start) {
                pq.pop();
                topInd = pq.top().second;
            }
            ans.push_back(arr[topInd]);
            start++;
            end++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends
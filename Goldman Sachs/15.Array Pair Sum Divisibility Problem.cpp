// Question Link: https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map<int,int> m;
        for(auto it: nums) {
            int mod = it%k;
            int toFind = k-mod;
            auto iteratorr = m.find(toFind);
            if(iteratorr==m.end()) {
                m[mod]++;
            } else {
                m[toFind]--;
                if(m[toFind]==0) {
                    m.erase(iteratorr);
                }
            }
        }
        if(m.size()==1) {
            for(auto it: m) {
                if(it.first==0) {
                    return ((it.second%2)==0);
                } else {
                    return false;
                }
            }
        }
        return m.size()==0;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends
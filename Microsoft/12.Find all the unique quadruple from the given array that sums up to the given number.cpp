// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        unordered_set<string> collection;
        
        sort(arr.begin(), arr.end());

        int n = arr.size();

        vector<vector<int>> ans;

        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {

                int l = 0;
                int r = n-1;

                while(l < r) {
                    if(l == i || l == j) {
                        ++l;
                        continue;
                    }
                    if(r == i || r == j) {
                        --r;
                        continue;
                    }

                    int sum = arr[i] + arr[j] + arr[l] + arr[r];

                    if(sum == k) {

                        vector<int> quadruple = {arr[i], arr[j], arr[l], arr[r]};
                        sort(quadruple.begin(), quadruple.end());
                        
                        string hash = "";
                        for(int num: quadruple) {
                            hash += to_string(num) + ':';
                        }

                        if(collection.count(hash) == 0) {
                            ans.push_back(quadruple);
                            collection.insert(hash);
                        }

                        ++l;
                        --r;
                    }
                    else if(sum < k) {
                        ++l;
                    }
                    else if(sum > k) {
                        --r;
                    }
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends

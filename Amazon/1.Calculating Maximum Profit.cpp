// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        // DP of Transaction Count vs Price
        vector<vector<int>> dp(K+1, vector<int>(N+1, 0));

        for(int t = 1; t <= K; ++t) {
            for(int p = 1; p <= N; ++p) {
                dp[t][p] = dp[t][p - 1];
                for(int i = 0; i < p; ++i) {
                    dp[t][p] = max(dp[t][p], dp[t-1][i] + A[p-1] - A[i]);
                }
            }
        }
        return dp.back().back();
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends

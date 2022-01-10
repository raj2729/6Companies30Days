// Question Link: https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1/#

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string matrixChainOrder(int p[], int n){
        // code here
        vector<vector<string>> ans(n-1,vector<string>(n,""));
        vector<vector<int>> dp(n-1,vector<int>(n,-1));
        for(int gap=1; gap<n; gap++) {
            for(int i=0, j=gap; j<n; i++,j++) {
                if(gap==1) {
                    ans[i][j] += char(int('A')+i);
                    dp[i][j] = 0;
                } else if(gap==2) {
                    string current = "";
                    current += '(';
                    current += char(int('A')+i);
                    current += char(int('A')+j-1);
                    current += ')';
                    ans[i][j] = current;
                    dp[i][j] = p[i]*p[j-1]*p[j];
                } else {
                    int start = i;
                    int end = j;
                    int maxCount = INT_MAX;
                    string ansString = "";
                    for(int k=start+1; k<end; k++) {
                        // cout<<"start k end: "<<start<<" "<<k<<" "<<end<<endl; 
                        int currentCount = dp[start][k] + p[start]*p[k]*p[end] + dp[k][end];
                        if(currentCount<maxCount) {
                            maxCount = currentCount;
                            ansString = "";
                            ansString += '(';
                            ansString += ans[start][k];
                            ansString += ans[k][end];
                            ansString += ')';
                        }
                    }
                    dp[start][end] = maxCount;
                    ans[start][end] = ansString;
                }
            }
        }
        return ans[0][n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
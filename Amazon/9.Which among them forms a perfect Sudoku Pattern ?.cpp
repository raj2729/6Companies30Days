// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        vector<bitset<10>> rowc(9), colc(9), bloc(9);

        for(int r = 0; r < 9; ++r) {
            for(int c = 0; c < 9; ++c) {
                int num = mat[r][c];
                
                if(
                    num && (
                    rowc[r].test(num) ||
                    colc[c].test(num) ||
                    bloc[3*(r/3) + c/3].test(num))
                ) return 0;
                
                rowc[r].set(num);
                colc[c].set(num);
                bloc[3*(r/3) + c/3].set(num);
            }
            
        }
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


 // } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& a)
{
    // Your code goes here
    int n=a.size();
    int limit = (n+1)/2;

    for(int r = 0; r < limit; ++r) {
        for(int c = r; c < n-r-1; ++c) {
            int temp = a[r][c];
            a[r][c] = a[c][n - r - 1];
            a[c][n - r - 1] = a[n - r - 1][n - c - 1];
            a[n - r - 1][n - c - 1] = a[n - c - 1][r];
            a[n - c - 1][r] = temp;
        }
    }
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}

  // } Driver Code Ends

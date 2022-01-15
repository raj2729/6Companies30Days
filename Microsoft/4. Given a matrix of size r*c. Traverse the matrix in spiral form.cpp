// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > m, int r, int c) 
    {
        // code here 
        int left=0,right=c-1,up=0,down=r-1;
        int i,j,direction=0;
        vector<int> v;
        while(left<=right && up<=down){
            if(direction == 0)
            {
                for(i=left;i<=right;i++){
                    v.push_back(m[up][i]);
                }
                up++;
            }
            else if(direction == 1)
            {
                for(i=up;i<=down;i++){
                    v.push_back(m[i][right]);
                }
                right--;
           
            }
            else if(direction == 2)
            {
                for(i=right;i>=left;i--){
                    v.push_back(m[down][i]);
                }
                down--;
            }
            else
            {
                for(i=down;i>=up;i--){
                    v.push_back(m[i][left]);
                }
                left++;
                }
            direction=(direction+1)%4;
        }
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends

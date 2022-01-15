// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int a[], int n)  { 
	    int i,j,sum=0;
	    for(i=0;i<=n-1;i++){
	        sum+=a[i];
	    }
	    bool dp[n+1][sum+1];

	    dp[0][0]=true;
	    for(i=1;i<=sum;i++){
	        dp[0][i]=false;
	    }
	    for(i=1;i<=n;i++){
	        dp[i][0]=true;
	    }
	    for(i=1;i<=n;i++){
	        for(j=1;j<=sum;j++){
	            if(a[i-1] <= j){
	                dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
	            }else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    i=sum/2;
	    bool flag=false;
	    while(flag==false){
	        if(dp[n][i]) flag=true;
	        else i--;
	    }
	    return (sum - 2*i);
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends

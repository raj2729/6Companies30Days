// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	// Your code here
	vector<string> ans(N);
	for(int i = 1; i <= N; ++i) {
	    int num = i;
	    while(num) {
	        ans[i - 1] += (char) ('0' + (num & 1));
	        num >>= 1;
	    }
	    reverse(ans[i - 1].begin(), ans[i - 1].end());
	}

	return ans;
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
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends

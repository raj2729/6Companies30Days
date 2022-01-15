// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<int> previous_peak;
        previous_peak.push(0);
        
        vector<int> ans(n);
        ans[0] = 1;

        for(int i = 1; i < n; ++i) {
            while(!previous_peak.empty() && price[previous_peak.top()] <= price[i]) {
                previous_peak.pop();
            }

            ans[i] = i - (previous_peak.empty() ? -1 : previous_peak.top());
            previous_peak.push(i);
        }

        return ans;
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends

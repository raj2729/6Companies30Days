//Question Link: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k) {
        
        // your code here
        vector<int> ans;
        deque<int> dq;
        int i=0, j=0;
        while(j<n) {
            if(dq.size()==0) dq.push_back(j); 
            else {
                while(dq.size()!=0 && arr[dq.back()]<=arr[j]) dq.pop_back(); 
                dq.push_back(j);
            }
            if(j-i+1==k) {
                int max = dq.front();
                ans.push_back(arr[max]);
                if(max==i) dq.pop_front();
                i++;
            }
            j++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
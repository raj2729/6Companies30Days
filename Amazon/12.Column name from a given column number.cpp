Question Link: https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/#

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
  public:
    string colName (long long int n) {
        string s = "";
        while(n != 0) {
            n -= 1;
            int charr = n % 26;
            s = string(1, charr + 'A') + s;
            n /= 26;
        }
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends
// Question Link: https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans = "";
		    queue<int> q;
		    vector<int> count(26,0);
		    for(auto &eachChar: A) {
		        int charToNumber = eachChar-'a';
		        count[charToNumber]++;
		        if(count[charToNumber]==1) {
		            q.push(charToNumber);
		        }
		        while(q.size()!=0 && count[q.front()]>=2) {
		            q.pop();
		        }
		        if(q.size()==0) {
		            ans += '#';
		        } else {
		            ans += char( q.front() + int('a') );
		        }
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
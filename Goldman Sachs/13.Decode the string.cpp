// Question Link: https://practice.geeksforgeeks.org/problems/decode-the-string2444/1#

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{

private:
    
    int stringToNumber(string s, int start, int size) {
        int ans = 0;
        for(int i=0, currPow = size-1; i<size; i++, currPow--) {
            ans += (s[start+i]-'0')*pow(10,currPow);
        }
        return ans;
    }
    
    pair<int,int> numberDetails(string &s, int index) {
        int count = 0;
        int value = 0;
        int start = index;
        while(isNum(s[start])) {
            count++;
            start++;
        }
        int number = stringToNumber(s, index, count);
        return {number,count};
    }
    
    bool isNum(char a) {
        return a>='0' && a<='9';
    }
    
    bool isChar(char a) {
        return a>='a' && a<='z';
    }
    
    string multiply(string s, int num) {
        string ans = "";
        for(int i=0; i<num; i++) 
            ans += s;
        return ans;
    }

    pair<string,int> solver(string &s, int start) {
        string ans = "";
        int n = s.size();
        for(int i=start; i<n; i++) {
            if(isNum(s[i])) {
                pair<int,int> numDetails = numberDetails(s,i);
                int count = numDetails.second;
                int factor = numDetails.first;
                pair<string,int> p = solver(s, i+count+1);
                ans += multiply(p.first,factor);
                i = p.second;
            } else if(isChar(s[i])) {
                ans += s[i];
            } else if(s[i]==']') {
                return {ans,i};
            }
        }
        return {ans,n};
    }

public:
    string decodedString(string s) {
        // code here
        return solver(s,0).first;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
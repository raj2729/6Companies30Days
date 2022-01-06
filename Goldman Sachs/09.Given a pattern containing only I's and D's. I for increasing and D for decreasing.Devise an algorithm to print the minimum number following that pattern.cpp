// Question Link: https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1#

class Solution{   
public:
    string printMinNumberForPattern(string S){
        int n = S.length();
        string ans = "";
        for(int i=1; i<=n+1; i++)
            ans += to_string(i);
        for(int i=0; i<n; i++) {
            if(S[i]=='D') {
                int start = i;
                while(i<n && S[i]=='D') 
                    i++;
                reverse(ans.begin()+start,ans.begin()+i+1);
            }
        }
        return ans;
    }
};


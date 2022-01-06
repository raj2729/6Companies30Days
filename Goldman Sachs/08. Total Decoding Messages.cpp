// Question Link: https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1/#

class Solution {
    
    private:
        
        int valForLastSecondIndex(char a, char b) {
            // if the number is in [1,26]
            if(isDouble(a,b)) {
        
                // the number is either 10 or 20
                // only single number can be formed as  0 alone cant make a number
                if(b=='0') return 1; 
                
                // else two numbers can be formed, for ex:24 can be represented as (24) and (2,4)
                return 2; 
                
            }
            
            // number with '0' alone has no value
            if(a=='0') return 0; 

            // these will be numbers like '80' or '90'
            // the first digit will be added with the previous set of numbers and form a numbers,
            // and left over 0s will act as trailing 0s
            if(b=='0') return 0; 

            return 1;
        }
    
        bool isDouble(char a, char b) {
            // check if the number is either 1 to 26 inclusive
            if( a=='1') return true;
            if(( a=='2') && ( b=='0' ||  b=='1' || b=='2' ||  b=='3' ||  b=='4' || b=='5' ||  b=='6' ) )
                return true;
            return false;
    }
    
	public:
		int CountWays(string str){
		    int M = 1000000007; 
		    int n = str.length();
		    if(n==1) return str[0]=='0'?0:1;
		    vector<int> dp(n,0);
		    dp[n-1] = str[n-1]=='0' ? 0 : 1;
		    dp[n-2] = valForLastSecondIndex(str[n-2],str[n-1]) ;
		    for(int i=n-3; i>=0; i--) {
		        if(str[i]=='0') {
		            if(str[i+1]=='0') return 0; // invalid
		            dp[i] = 0;
		            continue;
		        }
		        if(str[i+1]=='0') {
		            if(str[i]!='1' && str[i]!='2') return 0;
		            dp[i] = dp[i+2];
		            continue;
		        }
		        if(isDouble(str[i],str[i+1])) {
		            dp[i] = ((dp[i+1])%M + (dp[i+2])%M)%M;
		        } else {
		            dp[i] = dp[i+1];
		        }
		    }
		    for(int i=0; i<n; i++) {
		        if(str[i]!=0) return dp[i];
		    }
		    return 0;
		}

};

// Question Link: https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/#

class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    if(n==1) return 1;
	    vector<ull> uglyNums;
	    uglyNums.push_back(1);
	    int done = 1;
	    int p2=0, p3=0, p5=0;
	    unordered_set<ull> consideredNumbers;
	    while(done!=n) {
	        ull val1 = 2*uglyNums[p2];
	        ull val2 = 3*uglyNums[p3];
	        ull val3 = 5*uglyNums[p5];
	        if(val1<=val2 && val1<=val3) {
	           if(consideredNumbers.find(val1)==consideredNumbers.end()) {
	               consideredNumbers.insert(val1);
	               uglyNums.push_back(val1);
	               done++;
	           }    
	           p2++;
	        } else if(val2<=val1 && val2<=val3) {
	           if(consideredNumbers.find(val2)==consideredNumbers.end()) {
	               consideredNumbers.insert(val2);
	               uglyNums.push_back(val2);
	               done++;
	           }    
	           p3++;	            
	        } else if(val3<=val1 && val3<=val2) {
	           if(consideredNumbers.find(val3)==consideredNumbers.end()) {
	               consideredNumbers.insert(val3);
	               uglyNums.push_back(val3);
	               done++;
	           }    
	           p5++;	            
	        }
	    }
	    return uglyNums[n-1];
	}
};
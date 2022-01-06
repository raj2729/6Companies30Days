// Question Link: https://practice.geeksforgeeks.org/problems/run-length-encoding/1/


string encode(string src) {     
  //Your code here 
  int n = src.length();
  int low = 0, high = 0;
  string ans = "";
  while(high<n) {
    char current = src[low];
    while(high<n-1 && src[high+1]==src[low])
        high++;
    ans += src[low] + to_string(high-low+1);
    high = high+1;
    low = high;
  }
  return ans;
}    
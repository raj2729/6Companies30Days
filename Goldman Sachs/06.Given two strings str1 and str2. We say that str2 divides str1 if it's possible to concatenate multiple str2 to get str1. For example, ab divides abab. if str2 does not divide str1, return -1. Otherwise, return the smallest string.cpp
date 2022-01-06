// Question Link: https://leetcode.com/problems/greatest-common-divisor-of-strings/submissions/

// Question: Given two strings str1 and str2. We say that str2 divides str1 if it's possible to concatenate multiple str2 to get str1. For example, ab divides abab. if str2 does not divide str1, return -1. Otherwise, return the smallest string

class Solution {
 
private:
    int gcd(int a, int b) {
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
    
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1) return "";
        int l1 = str1.length();
        int l2 = str2.length();
        int gcdd = gcd(l1,l2);
        return str1.substr(0,gcdd);
    }
};

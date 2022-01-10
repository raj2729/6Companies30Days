// Question Link: https://leetcode.com/problems/longest-mountain-in-array/

class Solution {
public:
    int longestMountain(vector<int>& a) {
        int n = a.size();
        if(n<3) return 0;
        int start = 0;
        int end = 1;
        int ans = 0;
        while(end<n) {
            int initialStart = start;
            while(end<n && a[start]<a[end]) {
                start++;
                end++;
            }
            int upLen = end - initialStart;
            if(end<n && a[start]==a[end]) {
                while(end<n && a[start]==a[end]) {
                    start++;
                    end++;
                }
                continue;
            }
            int initialDown = end-1;
            start = end - 1;
            end = start + 1;
            while(end<n && a[start]>a[end]) {
                start++;
                end++;
            }
            int downLen = end - initialDown;
            if(upLen+downLen-1 >= 3 && upLen>1 && downLen>1) {
                ans = max(ans, upLen+downLen-1);
            }
            start = end - 1;
            end = start + 1;
        }
        return ans;
    }
};


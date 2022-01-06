// Question Link: https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int size = INT_MAX;
        int low = 0, high = 0;
        while(high<=n) {
            if(sum<target) {
                sum += high<n ? nums[high] : 0;
                high++;
            } else {
                size = min(size,high-low);
                sum -= nums[low];
                low++;
                if(low>high) high = low;
            }
        }
        if(sum>=target) size = min(size,high-low);
        return size==INT_MAX ? 0 : size;
    }
};
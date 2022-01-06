class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& nums, int n, long long k) {
        int low = 0;
        int high = 0;
        int ans = 0;
        long long prefixProduct = nums[0];
        while(high<n) {
            if(prefixProduct<k) {
                ans += high-low+1;
                high++;
                if(high<n) prefixProduct *= nums[high];
            } else {
                prefixProduct /= nums[low];
                low++;
                if(low>high) {
                    high++;
                    if(high<n) prefixProduct *= nums[high];
                }
            }
        }
        return ans;        
    }
};
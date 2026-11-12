class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        
        int ans = 1, inc = 1, dec = 1;

        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > 0) {
                inc++;
                dec = 1;
            }
            else if (nums[i] - nums[i - 1] < 0) {
                inc = 1;
                dec++;
            }
            else {
                inc = 1;
                dec = 1;
            }
            ans = max({ans, inc, dec});
        }
        return ans;
    }
};
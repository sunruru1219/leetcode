class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int prev = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; ++i) {
            int sum = prev + nums[i];
            if (sum > nums[i]) prev = sum;
            else prev = nums[i];

            ans = max(ans, prev);
        }

        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) continue;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1, k = n - 1;
            while (j < k) {
                int left = nums[j], right = nums[k]; 
                int target = -nums[i];
                if (target == left + right) {
                    ans.push_back({-target, left, right});
                    while (j < k && nums[j] == left) j++;
                    while (j < k && nums[k] == right) k--;
                }
                else if (target > left + right)
                    while (j < k && nums[j] == left) j++;
                else 
                    while (j < k && nums[k] == right) k--;
            }
        }
        return ans;
    }
};
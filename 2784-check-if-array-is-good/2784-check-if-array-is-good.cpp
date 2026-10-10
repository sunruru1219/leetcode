class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1; // length = n + 1

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return false;
        }

        if (nums[n] == n) return true;
        return false;

    }
};
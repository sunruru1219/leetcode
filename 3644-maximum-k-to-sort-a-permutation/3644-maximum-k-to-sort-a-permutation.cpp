class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        int ans;
        bool s = false;
        // s = true if there is at least one element that is not in its correct position
        // s = false if nums is already sorted
        for (int i = 0; i < n; ++i) {
            if (!s && nums[i] != i) {
                ans = i;
                s = true;
            }
            else if (s && nums[i] != i) ans &= i;
        }

        return s ? ans : 0;
    }
};
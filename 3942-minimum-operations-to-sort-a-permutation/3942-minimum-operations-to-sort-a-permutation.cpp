class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 0;
        else if (n == 2) return nums[0] == 0 ? 0 : 1;

        int gapMoreThanOne = 0;
        bool incre_set = false;
        bool increasing = true;
        int zero = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > 1) {
                gapMoreThanOne++;
                increasing = false;
            }
            else if (nums[i] - nums[i - 1] < -1) {
                gapMoreThanOne++;
            }

            if (!incre_set && abs(nums[i] - nums[i - 1]) == 1) {
                if (nums[i] - nums[i - 1] == 1) increasing = true;
                else increasing = false;
                incre_set = true;
            }
            if (nums[i] == 0) zero = i;
        }
        if (abs(nums[n - 1] - nums[0]) > 1) gapMoreThanOne++;
        
        if (gapMoreThanOne > 1) return -1;

        if (gapMoreThanOne == 0) {
            if (increasing) return 0;
            return 1;
        }

        if (increasing) {
            return min(zero, n - zero + 2);
        }
        return min(n - zero, zero + 2);
    }
};
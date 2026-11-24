class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            long long LCM = nums[i];
            long long GCD = nums[i];
            long long PRO = nums[i];

            for (int j = i + 1; j < n; ++j) {
                LCM = lcm(LCM, nums[j]);
                GCD = gcd(GCD, nums[j]);
                PRO *= nums[j];
                
                if (PRO == LCM * GCD) ans = max(ans, j - i + 1);
                else if (PRO > LCM * GCD) break;
            }
        }
        return ans;
    }
};
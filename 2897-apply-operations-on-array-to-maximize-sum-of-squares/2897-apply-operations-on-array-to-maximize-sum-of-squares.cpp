class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> cnt(30, 0);
        const int MOD = 1e9 + 7;

        for (int n : nums) {
            int i = 0;
            while (n > 0) {
                if (n % 2) cnt[i]++;
                i++;
                n /= 2;
            }
        }

        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            int times = 1;
            long long element = 0;
            for (int d = 0; d < 30; d++) {
                if (cnt[d] > 0) {
                    element += times;
                    cnt[d]--;
                }
                times *= 2;
            }
            ans += (element * element) % MOD;
            ans %= MOD;
        }

        return (int)ans;
    }
};
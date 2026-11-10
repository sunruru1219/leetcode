class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < n + 1; ++i) {
            if (i == 1) {
                dp[i] = costs[i - 1] + 1;
            }
            else if (i == 2) {
                dp[i] = costs[i - 1] + min(4,          // 0 -> 2
                                          dp[1] + 1);  // 1 -> 2
            }
            else {
                dp[i] = costs[i - 1] + min({
                    dp[i - 1] + 1,
                    dp[i - 2] + 4,
                    dp[i - 3] + 9
                });
            }
        }


        return dp[n];
    }
};
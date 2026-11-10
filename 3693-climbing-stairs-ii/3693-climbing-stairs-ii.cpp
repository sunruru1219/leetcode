class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int dp1 = 0, dp2 = 0, dp3 = 0;
        for (int i = 1; i <= n; ++i) {
            int dp0 = costs[i - 1] + min({
                dp1 + 1,
                dp2 + 4,
                dp3 + 9
            });

            dp3 = dp2;
            dp2 = dp1;
            dp1 = dp0;
        }


        return dp1;
    }
};
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        map<int, int> dp;
        int ans = 0;

        for (int x : nums) {
            // use x + 1
            dp[x + 1] = max(dp[x + 1], dp[x] + 1);
            
            // use x
            dp[x] = max(dp[x], dp[x - 1] + 1);

            ans = max({ans, dp[x + 1], dp[x]});
        }
        return ans;
    }
};
/*
O(n^2) too slow
        // dp[i][0]: choose nums[i] as last number of consecutive elements
        // dp[i][0]: choose nums[i] + 1 as last number of consecutive elements
        vector<vector<int>> dp(n, vector<int>(2, 1));

        int ans = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int prev = nums[j];
                int x = nums[i];
                
                if (prev + 1 == x) dp[i][0] = max(dp[i][0], dp[j][0] + 1);
                if (prev + 2 == x) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                if (prev + 1 == x + 1) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                if (prev + 2 == x + 1) dp[i][1] = max(dp[i][1], dp[j][1] + 1);

                ans = max({ans, dp[i][0], dp[i][1]});
            }
        }

        return ans;
    }
};
*/
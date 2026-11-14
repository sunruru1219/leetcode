class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        int ans = INT_MAX;

        // go through every possible length
        for (int len = l; len <= r; len++) {
            int sum = 0;
            for (int i = 0; i < len; ++i) {
                sum += nums[i];
            }
            //cout << sum << " ";
            if (sum > 0) ans = min(ans, sum);

            // 將整個區間向後移一格
            int head = 0;
            for (int j = len; j < n; ++j) {
                sum -= nums[head];
                head++;
                sum += nums[j];
            //cout << sum << " ";

                if (sum > 0) ans = min(ans, sum);
            }
            //cout << endl;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
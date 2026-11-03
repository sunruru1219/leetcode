class Solution {
public:
    int minMoves(vector<int>& nums) {
        int M = nums[0];
        for (int i : nums) M = max(M, i);

        int ans = 0;
        for (int i : nums) ans += abs(M - i);

        return ans;
    }
};
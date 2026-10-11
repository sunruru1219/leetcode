class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, idx = 1;
        for (int i : nums) {
            if (n % idx == 0) ans += i * i;
            idx++;
        }
        return ans;
    }
};
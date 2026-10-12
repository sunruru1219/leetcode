class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int r = nums[0]; // 第一台車的油
        if (r == 0) return false;
        for (int i = 1; i < nums.size()-1; ++i) {
            r-=1;
            if (nums[i] > r) r = nums[i]; // 遇到油多的車就換
            if (r == 0) return false;
        }
        if (r > 0) return true;
        return false;
    }
};
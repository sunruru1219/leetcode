class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int small = 0;
        int cnt = 0;
        for (int i : nums) {
            if (i < target) small++;
            else if (i == target) cnt++;
        }

        while (cnt > 0) {
            ans.push_back(small);
            small++;
            cnt--;
        }

        return ans;
    }
};
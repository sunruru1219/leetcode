class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int unique = -101;
        for (int i = 0; i < nums.size(); ++i) {
            // unique
            if (nums[i] != unique) {
                unique = nums[i];
                nums[k] = unique;
                k+=1;
            }
        }

        return k;
    }
};
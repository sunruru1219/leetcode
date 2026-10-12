class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int unique = nums[0];
        int t = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == unique) {
                t+=1;
                if (t <= 2) {
                    nums[k] = nums[i];
                    k+=1;
                }
            }
            else {
                unique = nums[i];
                t = 1;
                nums[k] = nums[i];
                k+=1;
            }
        }
        return k;
    }
};
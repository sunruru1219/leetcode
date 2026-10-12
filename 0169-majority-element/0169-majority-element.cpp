class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candicate = nums[0];
        int count = 1;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (count == 0) {
                candicate = nums[i];
                count = 1;
            }
            else if(nums[i] == candicate) {
                count++;
            }
            else {
                count--;
            }
        }
        count = 0;
        for(int i = 0; i < n; ++i) {
            if (nums[i] == candicate){
                count++;
            }
        }
        if (count>n/2) {
            return candicate;
        }
        return 0;
    }
};
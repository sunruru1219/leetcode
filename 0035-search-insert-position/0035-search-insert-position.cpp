class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int L = 0, R = n;
        while (L < R) {
            int mid = L + (R - L) / 2;
            if (nums[mid] < target) {
                L = mid + 1;
            }
            else {
                R = mid;
            }
        }

        return L;
    }
};
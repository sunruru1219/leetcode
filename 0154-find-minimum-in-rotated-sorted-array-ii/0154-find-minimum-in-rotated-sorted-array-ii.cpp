class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        while (left + 1 < n && nums[left] == nums[left + 1]) {
            left++;
        }
        int right = n - 1;
        while (right - 1 >= 0 && nums[right] == nums[right - 1]) {
            right--;
        }
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;
                while (right - 1 >= 0 && nums[right] == nums[right - 1]) right--;
            }
            else {
                left = mid + 1;
                while (left + 1 < n && nums[left] == nums[left + 1]) left++;
            }
        }
        return nums[left];
    }
};
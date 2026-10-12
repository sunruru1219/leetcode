class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int m_ = m-1;
        int n_ = n-1;
        int last = m+n-1;
        while (m_ >= 0 && n_ >= 0) {
            // case1: nums1>nums2
            if (nums1[m_] > nums2[n_]) {
                nums1[last] = nums1[m_];
                last -= 1;
                m_ -= 1;
            }
            // case2: nums1<nums2
            else {
                nums1[last] = nums2[n_];
                last -= 1;
                n_ -= 1;
            }
        }
        
        // if nums1 still has remain elements, skip
        // if nums2 still has remain elements, add them to the head of nums1
        for (int i = n_; i>=0; i--) {
            nums1[last] = nums2[i];
            last-=1;
        }
    }
};
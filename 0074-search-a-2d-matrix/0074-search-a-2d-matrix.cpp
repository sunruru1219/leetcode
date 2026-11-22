class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int L = 0, R = m * n;

        while (L < R) {
            int mid = L + (R - L) / 2;
            int mid_num = matrix[mid / n][mid % n];
            if (mid_num < target) {
                L = mid + 1;
            }
            else {
                R = mid;
            }
        }
        return L < m * n && matrix[L / n][L % n] == target;
    }
};
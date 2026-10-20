class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        bool firstRow = false, firstCol = false;

        // 用firstRow/firstCol記錄第一列/行是否最終要設成0
        for (int j = 0; j < m; ++j) {
            if (matrix[0][j] == 0) firstRow = true;
        }
        for (int i = 0; i < n; ++i) {
            if (matrix[i][0] == 0) firstCol = true;
        }

        // 接著在遍歷其他格子
        // 若(i, j)為0 則將第一行的第i個以及第一列的第j個標為0
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // 根據第一行&第一列的標記 將該設成0的element通通設成0
        for (int i = 1; i < n; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < m; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < m; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < n; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        // 若firstRow/firstCol為true 則將第一列/行設成0
        if (firstRow) {
            for (int j = 0; j < m; ++j) {
                matrix[0][j] = 0;
            }
        }
        if (firstCol) {
            for (int i = 0; i < n; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
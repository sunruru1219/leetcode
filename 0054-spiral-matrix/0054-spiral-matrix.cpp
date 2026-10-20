class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(); 
        int m = matrix[0].size();

        vector<vector<int>> done(n, vector<int>(m, 0));

        int total = m * n;
        vector<int> ans;
        int i = 0, j = 0;
        char dir = 'r';
        while (total > 0) {
            // right
            switch(dir) {
                case 'r':
                    ans.push_back(matrix[i][j]);
                    done[i][j] = 1;
                    if (j + 1 < m && done[i][j+1] == 0) j++;
                    else {
                        dir = 'd';
                        i++;
                    }
                    break;
                case 'd':
                    ans.push_back(matrix[i][j]);
                    done[i][j] = 1;
                    if (i + 1 < n && done[i+1][j] == 0) i++;
                    else {
                        dir = 'l';
                        j--;
                    }
                    break;
                case 'l':
                    ans.push_back(matrix[i][j]);
                    done[i][j] = 1;
                    if (j - 1 >= 0 && done[i][j - 1] == 0) j--;
                    else {
                        dir = 'u';
                        i--;
                    }
                    break;
                case 'u':
                    ans.push_back(matrix[i][j]);
                    done[i][j] = 1;
                    if (i - 1 >= 0 && done[i- 1][j] == 0) i--;
                    else {
                        dir = 'r';
                        j++;
                    }
                    break;
            } 

            total--;
        } 
        return ans;
    }
};
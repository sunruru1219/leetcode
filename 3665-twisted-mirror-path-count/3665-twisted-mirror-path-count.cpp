class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp = vector(m ,vector(n, 0));
        dp[0][0] = 1;
        
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                // 無法抵達(x, y)或是那格是鏡子 都要跳過
                if (dp[x][y] == 0 || grid[x][y] == 1) continue;
                
                // down
                if (x + 1 < m) {
                    int x_ = x + 1;
                    int y_ = y;
                    if (grid[x_][y_] == 0) {
                        dp[x_][y_] = (dp[x_][y_] + dp[x][y]) % MOD;
                    }
                    else {
                        y_++;
                        char dir = 'R';
                        while (x_ < m && y_ < n && grid[x_][y_] == 1) {
                            if(dir == 'R') {
                                x_++;
                                dir = 'D';
                            }
                            else {
                                y_++;
                                dir = 'R';
                            }
                        }
                        if (x_ < m && y_ < n) {
                            dp[x_][y_] = (dp[x_][y_] + dp[x][y]) % MOD;
                        }
                    }
                }
                // right
                if (y + 1 < n) {
                    int x_ = x;
                    int y_ = y + 1;
                    if (grid[x_][y_] == 0) {
                        dp[x_][y_] = (dp[x_][y_] + dp[x][y]) % MOD;
                    }
                    else {
                        x_++;
                        char dir = 'D';
                        while (x_ < m && y_ < n && grid[x_][y_] == 1) {
                            if (dir == 'R') {
                                x_++;
                                dir = 'D';
                            }
                            else {
                                y_++;
                                dir = 'R';
                            }
                        }
                        if (x_ < m && y_ < n) {
                            dp[x_][y_] = (dp[x_][y_] + dp[x][y]) % MOD;
                        }
                    }
                }
            }
        }

        return dp[m - 1][n - 1] % MOD;
    }
};
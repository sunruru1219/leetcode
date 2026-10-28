class Solution {
public:
    int ans = INT_MAX;
    int m, n;
    vector<vector<vector<bool>>> dp;

    void dfs(vector<vector<int>>& grid, int x, int y, int cost) {
        if (x == m - 1 && y == n - 1) ans = min(ans, cost);

        if (x + 1 < m) {
            int newCost = cost ^ grid[x + 1][y];
            if (!dp[x + 1][y][newCost]) {
                dp[x + 1][y][newCost] = true;
                dfs(grid, x + 1, y, newCost);
            }
        }
        if (y + 1 < n) {
            int newCost = cost ^ grid[x][y + 1];
            if (!dp[x][y + 1][newCost]) {
                dp[x][y + 1][newCost] = true;
                dfs(grid, x, y + 1, newCost);
            }
        }
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp = vector(m, vector(n, vector(1024, false)));

        dp[0][0][grid[0][0]] = true;
        dfs(grid, 0, 0, grid[0][0]);

        return ans;
    }
};
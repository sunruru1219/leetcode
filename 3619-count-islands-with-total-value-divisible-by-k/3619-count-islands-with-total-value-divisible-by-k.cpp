class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        vector<pair<int, int>> dir = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;

                long long sum = 0;
                q.push({i, j});
                sum += grid[i][j] % k;
                sum %= k;
                grid[i][j] = 0;

                while (!q.empty()) {
                    auto cor = q.front();
                    q.pop();
                    int x = cor.first;
                    int y = cor.second;

                    for (auto d : dir) {
                        int dx = x + d.first;
                        int dy = y + d.second;

                        if (0 <= dx && dx < m && 0 <= dy && dy < n) {
                            if (grid[dx][dy] != 0) {
                                q.push({dx, dy});
                                sum += grid[dx][dy] % k;
                                sum %= k;
                                grid[dx][dy] = 0;
                            }
                        }
                    }
                }

                if (sum % k == 0) ans++;
            }
        } 
        return ans;
    }
};
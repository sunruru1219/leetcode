class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        vector<pair<int, int>> dir = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> fake_land; // lands on four sides and lands connect to them should be transfer to water for further calculation
        
        // add the coordinates of lands on four sides into "fake_land"(queue)
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) {
                fake_land.push({i, 0});
                grid[i][0] = 1;
            }
            if (grid[i][n - 1] == 0) {
                fake_land.push({i, n - 1});
                grid[i][n - 1] = 1;
            }
        }
        
        for (int j = 0; j < n; ++j) {
            if (grid[0][j] == 0) {
                fake_land.push({0, j});
                grid[0][j] = 1;
            }
            if (grid[m - 1][j] == 0) {
                fake_land.push({m - 1, j});
                grid[m - 1][j] = 1;
            }
        }

        // change fake_lands and lands connect to them into water (0 -> 1)
        // using BFS
        while (!fake_land.empty()) {
            auto cor = fake_land.front();
            fake_land.pop();
            int x = cor.first;
            int y = cor.second;

            for (auto d : dir) {
                int dx = x + d.first;
                int dy = y + d.second;

                if (0 <= dx && dx < m && 0 <= dy && dy < n) {
                    if (grid[dx][dy] == 0) {
                        fake_land.push({dx, dy});
                        grid[dx][dy] = 1;
                    }
                }
            }
        }

        // we just need to calculate the number of connected compants of lands
        // traverse grid, when grid[i][j] == 0, ans += 1
        // doing BFS from (i, j) to change all lands connected to 1
        // so that we wont calculate this land twice
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) continue;

                ans += 1;
                queue<pair<int, int>> con; // add cor of connected lands
                con.push({i, j});
                grid[i][j] = 1;
                
                while (!con.empty()) {
                    auto cor = con.front();
                    con.pop();

                    int x = cor.first;
                    int y = cor.second;

                    for (auto d : dir) {
                        int dx = x + d.first;
                        int dy = y + d.second;

                        if (0 <= dx && dx < m && 0 <= dy && dy < n) {
                            if (grid[dx][dy] == 0) {
                                con.push({dx, dy});
                                grid[dx][dy] = 1;
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};
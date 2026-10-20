class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board[0].size();
        int n = board.size();

        vector<pair<int, int>> dir = {
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0, -1},          { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1}
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int live = 0;

                for (auto [dx, dy] : dir) {
                    int x = i + dx;
                    int y = j + dy;
                    if (x >= 0 && x < n && y >= 0 && y < m) {
                        if (board[x][y] > 0) live++;
                    }
                }
                // origin state: live
                if (board[i][j] > 0) {
                    // live -> die: 1 -> 2
                    if (live < 2 || live > 3) board[i][j] = 2;
                }
                // origin state: die
                else {
                    // die -> live: 0 -> -1
                    if (live == 3) board[i][j] = -1;
                }
            }
        }

        // restore
        for (int i = 0;i < n; i++) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 2) board[i][j] = 0;
                else if (board[i][j] == -1) board[i][j] = 1;
            }
        }
    }
};
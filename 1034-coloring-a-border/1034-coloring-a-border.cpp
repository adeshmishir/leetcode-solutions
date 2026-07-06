class Solution {
    bool check(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    bool border(int i, int j, int val, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
            return true;

        if (grid[i + 1][j] != val) return true;
        if (grid[i - 1][j] != val) return true;
        if (grid[i][j + 1] != val) return true;
        if (grid[i][j - 1] != val) return true;

        return false;
    }

public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<pair<int, int>> borders;

        queue<pair<int, int>> q;
        int val = grid[row][col];

        q.push({row, col});
        vis[row][col] = true;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (border(x, y, val, grid))
                borders.push_back({x, y});

            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (check(nx, ny, m, n) &&
                    !vis[nx][ny] &&
                    grid[nx][ny] == val) {

                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        for (auto &p : borders)
            grid[p.first][p.second] = color;

        return grid;
    }
};
class Solution {
    bool check(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

public:
    int minimumEffortPath(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int effort = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if (effort > dist[x][y])
                continue;

            if (x == m - 1 && y == n - 1)
                return effort;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (!check(nx, ny, m, n))
                    continue;

                int newEffort = max(effort, abs(nums[x][y] - nums[nx][ny]));

                if (newEffort < dist[nx][ny]) {
                    dist[nx][ny] = newEffort;
                    pq.push({newEffort, {nx, ny}});
                }
            }
        }

        return 0;
    }
};
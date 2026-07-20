class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : edges) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
        }
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[0][1]=0;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({0, {0, 1}});
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int node = it.second.first;
            int cnt = it.second.second;
            if (cnt > k)
                continue;
            if (d > dist[node][cnt])
                continue;
            dist[node][cnt] = d;
            for (auto p : adj[node]) {
                int nxtNode = p.first;
                int nxtNodeDist = p.second;
                int newCnt = 1;
                if (labels[node] == labels[nxtNode])
                    newCnt = cnt + 1;
                int newDist = nxtNodeDist + d;
                if (newDist < dist[nxtNode][newCnt]) {
                    dist[nxtNode][newCnt] = newDist;
                    pq.push({newDist, {nxtNode, newCnt}});
                }
            }
        }
        int ans = INT_MAX;
        for (int c = 0; c <= k; c++)
            ans = min(ans, dist[n - 1][c]);

        return ans == INT_MAX ? -1 : ans;
    }
};
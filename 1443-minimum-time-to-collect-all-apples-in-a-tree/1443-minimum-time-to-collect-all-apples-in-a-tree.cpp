class Solution {
    unordered_map<int, bool> map;
    int solve(int node, vector<vector<int>> &adj, vector<bool>& hasApple) {
    map[node]=true;
        int sum = 0;
        int val = 0;
        for (auto it : adj[node]) {
            if (!map[it]) {
                map[it] = true;
                int v = solve(it, adj, hasApple);
                sum += v;
            }
        }

        if (sum || hasApple[node])
            val += 2;
        cout << node << " " << val + sum << endl;
        return val + sum;
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return max(0, solve(0, adj, hasApple) - 2);
    }
};
using ll = long long;

class Solution {
public:
    bool check(ll score, vector<vector<pair<ll,ll>>> &adj, ll k) {
        int n = adj.size();
        vector<ll> dist(n, LLONG_MAX);
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if(d != dist[node]) continue;
            if(d > k) continue;

            for(auto &it : adj[node]) {
                ll v = it.first;
                ll cost = it.second;

                if(cost < score) continue;

                if(d + cost < dist[v]) {
                    dist[v] = d + cost;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<ll,ll>>> adj(n);

        ll high = 0;

        for(auto &it : edges) {
            ll u = it[0];
            ll v = it[1];
            ll cost = it[2];

            if(online[u] && online[v]) {
                adj[u].push_back({v, cost});
                high = max(high, cost);
            }
        }

        ll low = 0;
        ll ans = -1;

        while(low <= high) {
            ll mid = low + (high - low) / 2;

            if(check(mid, adj, k)) {
                ans = mid;
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
using ll = long long;

class Solution {
    vector<ll> dp;

    ll solve(int i, vector<vector<int>>& rides) {
        if (i == rides.size()) return 0;

        if (dp[i] != -1) return dp[i];

        int nextIndex = lower_bound(
            rides.begin(),
            rides.end(),
            vector<int>{rides[i][1], 0, 0}
        ) - rides.begin();

        ll take = rides[i][1] - rides[i][0] + rides[i][2]
                + solve(nextIndex, rides);

        ll skip = solve(i + 1, rides);

        return dp[i] = max(take, skip);
    }

public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());

        dp.assign(rides.size(), -1);

        return solve(0, rides);
    }
};
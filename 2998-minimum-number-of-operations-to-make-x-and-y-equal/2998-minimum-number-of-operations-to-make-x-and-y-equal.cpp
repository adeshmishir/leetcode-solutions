class Solution {
    unordered_map<int, int> dp;

    int solve(int x, int y) {
        if (x <= y) return y - x;

        if (dp.count(x)) return dp[x];

        int ans = x - y;

        int rem5 = x % 5;

        ans = min(ans, rem5 + 1 + solve(x / 5, y));

        if (rem5 != 0) {
            ans = min(ans, 5 - rem5 + 1 + solve(x / 5 + 1, y));
        }

        int rem11 = x % 11;

        ans = min(ans, rem11 + 1 + solve(x / 11, y));

        if (rem11 != 0) {
            ans = min(ans, 11 - rem11 + 1 + solve(x / 11 + 1, y));
        }

        return dp[x] = ans;
    }

public:
    int minimumOperationsToMakeEqual(int x, int y) {
        return solve(x, y);
    }
};
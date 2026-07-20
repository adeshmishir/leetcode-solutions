class Solution {
public:
    using ll = long long;
    int MOD = 1e9 + 7;

    long long maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        ll lo = 1, hi = 0;

        for (int x : value)
            hi = max(hi, (ll)x);

        auto countTerms = [&](ll g) {
            ll cnt = 0;
            for (int i = 0; i < value.size(); i++) {
                if (value[i] < g) continue;
                cnt += (value[i] - g) / decay[i] + 1;
                if (cnt >= m) return cnt;
            }
            return cnt;
        };

        // Binary search threshold
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            if (countTerms(mid) >= m)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        ll threshold = hi;

        ll ans = 0;
        ll taken = 0;

        for (int i = 0; i < value.size(); i++) {

            if (value[i] <= threshold) continue;

            ll cnt = (value[i] - (threshold + 1)) / decay[i] + 1;

            taken += cnt;

            ll first = value[i];
            ll last = value[i] - (cnt - 1) * 1LL * decay[i];

            ll sum = cnt * (first + last) / 2;

            ans = (ans + sum) % MOD;
        }

        // Remaining selections all contribute threshold
        ans = (ans + ((ll)(m - taken) * threshold) % MOD) % MOD;

        return ans;
    }
};
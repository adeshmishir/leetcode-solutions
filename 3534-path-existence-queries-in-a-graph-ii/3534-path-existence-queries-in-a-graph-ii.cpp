class Solution {
public:
    vector<int> pathExistenceQueries(
        int n,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries
    ) {
        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }

        sort(arr.begin(), arr.end());

        vector<int> value(n);
        vector<int> position(n);

        for (int i = 0; i < n; i++) {
            value[i] = arr[i].first;
            position[arr[i].second] = i;
        }

        vector<int> component(n);
        int componentId = 0;

        component[0] = 0;

        for (int i = 1; i < n; i++) {
            if ((long long)value[i] - value[i - 1] > maxDiff) {
                componentId++;
            }

            component[i] = componentId;
        }

        vector<int> next(n);

        int right = 0;

        for (int left = 0; left < n; left++) {
            right = max(right, left);

            while (
                right + 1 < n &&
                (long long)value[right + 1] - value[left] <= maxDiff
            ) {
                right++;
            }

            next[left] = right;
        }

        int LOG = 1;

        while ((1LL << LOG) <= n) {
            LOG++;
        }

        vector<vector<int>> jump(LOG, vector<int>(n));

        for (int i = 0; i < n; i++) {
            jump[0][i] = next[i];
        }

        for (int level = 1; level < LOG; level++) {
            for (int i = 0; i < n; i++) {
                jump[level][i] =
                    jump[level - 1][jump[level - 1][i]];
            }
        }

        vector<int> answer;

        for (auto& query : queries) {
            int u = position[query[0]];
            int v = position[query[1]];

            if (u > v) {
                swap(u, v);
            }

            if (u == v) {
                answer.push_back(0);
                continue;
            }

            if (component[u] != component[v]) {
                answer.push_back(-1);
                continue;
            }

            int current = u;
            int steps = 0;

            for (int level = LOG - 1; level >= 0; level--) {
                if (jump[level][current] < v) {
                    current = jump[level][current];
                    steps += (1 << level);
                }
            }

            answer.push_back(steps + 1);
        }

        return answer;
    }
};
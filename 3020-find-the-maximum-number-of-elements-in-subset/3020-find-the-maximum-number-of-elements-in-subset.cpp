class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp;
        for(int x : nums) mp[x]++;

        int ans = 1;

        if(mp.count(1)) {
            int c = mp[1];
            if(c % 2 == 0) c--;
            ans = max(ans, c);
        }

        for(auto &p : mp) {
            long long val = p.first;
            if(val == 1) continue;

            int len = 0;

            while(mp.count(val)) {
                if(mp[val] >= 2) {
                    len += 2;
                } else {
                    len++;
                    break;
                }

                if(val > 1000000000LL / val) break;
                val = val * val;
            }

            if(len % 2 == 0) len--;

            ans = max(ans, len);
        }

        return ans;
    }
};
class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        unordered_map<char, int> freq;

        for (char c : s)
            freq[c]++;

        int target = n / 4;

        if (freq['Q'] == target && freq['W'] == target &&
            freq['E'] == target && freq['R'] == target)
            return 0;

        int ans = n;
        int left = 0;

        for (int right = 0; right < n; right++) {
            freq[s[right]]--;

            while (left <= right &&
                   freq['Q'] <= target &&
                   freq['W'] <= target &&
                   freq['E'] <= target &&
                   freq['R'] <= target) {

                ans = min(ans, right - left + 1);

                freq[s[left]]++;
                left++;
            }
        }

        return ans;
    }
};
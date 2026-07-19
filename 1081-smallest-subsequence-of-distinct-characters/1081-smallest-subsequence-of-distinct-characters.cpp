class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int> freq;
        unordered_map<char,bool> vis;

        for(char c : s)
            freq[c]++;

        stack<char> st;

        for(char c : s) {
            freq[c]--;

            if(vis[c])
                continue;

            while(!st.empty() &&
                  st.top() > c &&
                  freq[st.top()] > 0) {
                vis[st.top()] = false;
                st.pop();
            }

            st.push(c);
            vis[c] = true;
        }

        string ans;

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int j=0;int i=0;
        unordered_map<char,int>map;
        int ans=0;
        while(j<n){
            map[s[j]]++;
            while(map[s[j]]>1){
                map[s[i]]--;
                i++;
            }
            ans  = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
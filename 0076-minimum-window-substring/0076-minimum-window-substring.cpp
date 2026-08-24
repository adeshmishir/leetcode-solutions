class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        unordered_map<char,int>need,window;
        for(auto x:t)need[x]++;
        int formed=0,required=need.size();
        int left=0;int right=0;
        int ans = INT_MAX;
        int start = 0;
        
        while(right<m){
            char c = s[right];
            window[c]++;
            if(need.count(c) && window[c]==need[c])formed++;

            while(formed==required){
                if(ans>right-left+1){
                    start=left;
                    ans = right-left+1;
                }
                char ch = s[left];
                window[ch]--;
                left++;
                if(need.count(ch)&& window[ch]<need[ch])formed--;
            }
            right++;
        }
       if(ans<=m)return s.substr(start,ans);
        return "";
    }
};
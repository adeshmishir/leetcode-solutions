class Solution {
    bool solve(int j,string& s,unordered_map<string,bool>&map,vector<int>&dp){
        if(j>=s.size())return true;
        if(dp[j]!=-1){
        if(dp[j]==0)return false;
            return true;
        }
        string temp="";
        for(int i=j;i<s.size();i++){
            temp+=s[i];
            if(map[temp]&& solve(i+1,s,map,dp)){dp[j]=1;return true;}
        }
        dp[j]=0;
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>map;

        for(int i=0;i<wordDict.size();i++){
            map[wordDict[i]]=true;
        }
        vector<int>dp(s.size(),-1);
return solve(0,s,map,dp);
    }
};
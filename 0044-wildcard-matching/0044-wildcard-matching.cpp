class Solution {
    bool solve(int i,int j,string &s, string &p,vector<vector<int>>&dp){
        if(i>=s.size() && j>= p.size())return true;
        if(i>=s.size()){
            while(j<p.size() && p[j]=='*')j++;
            return j==p.size();
        }
        if(j>=p.size())return false;
        if(dp[i][j]!=-1)return dp[i][j]==1;
        if(p[j]=='?' || (s[i]==p[j])){
            return dp[i][j]= solve(i+1,j+1,s,p,dp);
        }
        else if(p[j]=='*'){
            return dp[i][j]= solve(i+1,j,s,p,dp)||solve(i,j+1,s,p,dp);
        }
        else {
            dp[i][j]=0;
            return false;
        }
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,s,p,dp);
    }
};
using ll = long long ;
class Solution {
    ll solve(string &s,string &t,int i,int j,vector<vector<ll>>&dp){
        if(j==t.size())return 1;
        if(i==s.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]= solve(s,t,i+1,j+1,dp)+solve(s,t,i+1,j,dp);
        }
        else{
            return dp[i][j]= solve(s,t,i+1,j,dp);
        }
    }
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<ll>>dp(m+1,vector<ll>(n+1,-1));
        return solve(s,t,0,0,dp);
    }
};
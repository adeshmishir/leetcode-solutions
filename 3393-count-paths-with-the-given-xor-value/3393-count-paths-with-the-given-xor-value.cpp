using ll = long long;
class Solution {
    int MOD = 1e9+7;
    bool check(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    ll solve(int i,int j,int x,vector<vector<int>>& grid,int k,vector<vector<vector<ll>>>&dp){
        int m=grid.size();int n = grid[0].size();
        if(!check(i,j,m,n))return 0;
        if(dp[i][j][x]!=-1)return dp[i][j][x];
        if(i==m-1 && j==n-1){
            if((x^grid[i][j])==k)return 1;
            else return 0;
        }
        return dp[i][j][x]=(solve(i+1,j,x^grid[i][j],grid,k,dp)+solve(i,j+1,x^grid[i][j],grid,k,dp))%MOD;
    }
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
         int m=grid.size();int n = grid[0].size();
         vector<vector<vector<ll>>>dp(m+1,vector<vector<ll>>(n+1,vector<ll>(16,-1)));
        return solve(0,0,0,grid,k,dp);
    }
};
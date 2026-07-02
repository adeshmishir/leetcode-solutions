class Solution {
    bool check(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        int m = grid.size();
        int n = grid[0].size();
        if(!check(i,j,m,n))return 0;
        if(grid[i][j]==1)return 0;
        if(i==m-1 && j==n-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]= solve(i+1,j,grid,dp)+solve(i,j+1,grid,dp);

    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,grid,dp);
    }
};
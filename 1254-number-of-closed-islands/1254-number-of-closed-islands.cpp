class Solution {
    bool check(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    void traverse(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&vis ){
         int m = grid.size();
        int n = grid[0].size();
          queue<pair<int,int>>q;
          vis[i][j]=1;
          q.push({i,j});
          while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            if(check(x,y+1,m,n) && !vis[x][y+1] && !grid[x][y+1]){
                vis[x][y+1]=1;
                q.push({x,y+1});
            }
            if(check(x+1,y,m,n) && !vis[x+1][y] && !grid[x+1][y]){
                vis[x+1][y]=1;
                q.push({x+1,y});
            }
            if(check(x,y-1,m,n) && !vis[x][y-1] && !grid[x][y-1]){
                vis[x][y-1]=1;
                q.push({x,y-1});
            }
            if(check(x-1,y,m,n) && !vis[x-1][y] && !grid[x-1][y]){
                vis[x-1][y]=1;
                q.push({x-1,y});
            }
        }
    }
    void markBoundry(vector<vector<int>>& grid,vector<vector<int>>&vis){
         int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || j==0 || i==m-1 || j==n-1) && !grid[i][j]){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            if(check(x,y+1,m,n) && !vis[x][y+1] && !grid[x][y+1]){
                vis[x][y+1]=1;
                q.push({x,y+1});
            }
            if(check(x+1,y,m,n) && !vis[x+1][y] && !grid[x+1][y]){
                vis[x+1][y]=1;
                q.push({x+1,y});
            }
            if(check(x,y-1,m,n) && !vis[x][y-1] && !grid[x][y-1]){
                vis[x][y-1]=1;
                q.push({x,y-1});
            }
            if(check(x-1,y,m,n) && !vis[x-1][y] && !grid[x-1][y]){
                vis[x-1][y]=1;
                q.push({x-1,y});
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        markBoundry(grid,vis);
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]&&!grid[i][j]){
                    ans++;
                    traverse(i,j,grid,vis);
                }
            }
        }
        return ans;

    }
};
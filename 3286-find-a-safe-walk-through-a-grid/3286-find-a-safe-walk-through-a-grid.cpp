class Solution {
    bool check(int i,int j,int m, int n){
        return i>=0 && j>=0 && j<n && i<m;
    }
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        bool ok=false;
        priority_queue<pair<int,pair<int,int>>>pq;
        int m = grid.size();
        int n = grid[0].size();
        map<pair<int,int>,bool>map;
       if(grid[0][0]){
         pq.push({health-1,{0,0}});
       }
       else  pq.push({health,{0,0}});
        while(!pq.empty()){
            auto it  = pq.top();
            pq.pop();
            int h = it.first;
            if(h<=0)break;
            int x = it.second.first;
            int y = it.second.second;
            if(map[{x,y}])continue;
            map[{x,y}]=true;
            if(x==m-1 && y==n-1){
                ok=true;
                break;
            }
            
            if(check(x+1,y,m,n)){
                if(grid[x+1][y])pq.push({h-1,{x+1,y}});
                else pq.push({h,{x+1,y}});
            }
            if(check(x-1,y,m,n)){
                if(grid[x-1][y])pq.push({h-1,{x-1,y}});
                else pq.push({h,{x-1,y}});
            }
            if(check(x,y+1,m,n)){
                if(grid[x][y+1])pq.push({h-1,{x,y+1}});
                else pq.push({h,{x,y+1}});
            }
            if(check(x,y-1,m,n)){
                if(grid[x][y-1])pq.push({h-1,{x,y-1}});
                else pq.push({h,{x,y-1}});
            }
        }
        return ok;
    }
};
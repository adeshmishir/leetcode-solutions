class Solution {
    bool check(int i,int j, int m , int n){
        return i>=0 && j>=0 && i<m && j<n;
    }

    
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>ans(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
int val=0;
        while(!q.empty()){
            int sz = q.size();
            cout<<sz<<" ";
            for(int v = 0;v<sz;v++){
                auto it = q.front();
                int i = it.first;
                int j = it.second;
                q.pop();
                if(!check(i,j,m,n))continue;
                if(ans[i][j]!=-1)continue;
                ans[i][j]=val;
                q.push({i+1,j});
                q.push({i-1,j});
                q.push({i,j+1});
                q.push({i,j-1});
            }
            val++;
        }
        return ans;
    }
};
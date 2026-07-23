class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& req) {
        vector<int>degree(n,0);
        vector<vector<int>>adj(n);
        for(auto &it:req){
            int u = it[0];
            int v = it[1];
            degree[u]++;
            adj[v].push_back(u);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(degree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int sub = q.front();
            q.pop();
            for(auto it:adj[sub]){
                degree[it]--;
                if(degree[it]==0)q.push(it);
            }
        }
        for(int i=0;i<n;i++){
            if(degree[i]!=0)return false;
        }
        return true;
    }
};
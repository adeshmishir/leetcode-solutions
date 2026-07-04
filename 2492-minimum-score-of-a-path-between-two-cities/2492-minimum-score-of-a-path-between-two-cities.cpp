class Solution {
    bool check(int node,vector<vector<int>>&adj ){
        if(node==adj.size())return true;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int node = q.front();
            q.pop();
             if(node==adj.size()-1)return true;
             for(auto it:adj[node]){
               if(it!=node) q.push(it);
             }
             adj[node].clear();
        }
        return false;
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int mini= INT_MAX;
        vector<vector<int>>adj(n+1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto &it:roads){
            int u = it[0];
            int v =it[1];
            int dist = it[2];
            adj[u].push_back(v);
            adj[v].push_back(u);
            pq.push({dist,u});
        }
        int ans = 0;
        while(!pq.empty()&& !ans){
            auto it  = pq.top();
            pq.pop();
            if(check(it.second,adj))ans=it.first;
        }
       return ans;
    }
};
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n =  graph.size();
        vector<int>degree(n,0);
        queue<int>q;
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(graph[i].size()==0)q.push(i);
           for(auto j:graph[i]){
            adj[j].push_back(i);
            degree[i]++;
           }
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                degree[it]--;
                if(degree[it]==0)q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
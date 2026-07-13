class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<vector<int>>adj(n);
        for(auto it:pairs){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int,bool>map;
        for(auto it:pairs){
            int u = it[0];
            if(map[u])continue;
            queue<int>q;
            q.push(u);
            map[u]=true;
            string p="";
            vector<int>ind;
            while(!q.empty()){
                int node=q.front();
                ind.push_back(node);
                q.pop();
                p.push_back(s[node]);
                for(auto v:adj[node]){
                    if(!map[v]){
                        map[v]=true;
                        q.push(v);
                    }
                }
            }
            sort(p.begin(),p.end());
            sort(ind.begin(),ind.end());
            for(int i=0;i<ind.size();i++){
                s[ind[i]]=p[i];
            }
        }
        return s;
    }
};
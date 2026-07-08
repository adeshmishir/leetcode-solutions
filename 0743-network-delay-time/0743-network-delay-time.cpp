class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>ans(n,INT_MAX);
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it :times){
            int a = it[0];
            int b = it[1];
            int time = it[2];
            adj[a-1].push_back({b-1,time});
        }
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        pq.push({0,k-1});
        // ans[k-1]=0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int time = it.first;
            int node = it.second;
            if(time>=ans[node])continue;
            ans[node]=time;
            for(auto v:adj[node]){
                int a = v.first;
                int b = v.second;
                pq.push({b+time,a});
            }
            
        }
        int val = *max_element(ans.begin(),ans.end());
        for(auto it:ans)cout<<it<<" ";
        if(val==INT_MAX)return -1;
        return val;

    }
};
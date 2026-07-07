using ll = long long;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>degree(n);
        for(auto &it:roads){
            int a = it[0];
            int b = it[1];
            degree[a]++;
            degree[b]++;
        }
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({degree[i],i});
        }
        degree.clear();
        int val = n;
        while(!pq.empty()){
            degree[pq.top().second]=val;
            val--;
            pq.pop();
        }
        ll ans = 0;
         for(auto &it:roads){
            int a = it[0];
            int b = it[1];
            ans+=(degree[a]+degree[b]);
        }
return ans;
    }
};
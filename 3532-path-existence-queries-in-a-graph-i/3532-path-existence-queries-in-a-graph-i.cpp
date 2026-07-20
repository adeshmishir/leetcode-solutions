class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>v;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff)v.push_back(i);
        }
        vector<bool>ans;
        for(auto it:queries){
            int a = it[0];int b = it[1];
            if(b<a)swap(a,b);
            if(a==b){
                ans.push_back(true);
                continue;
            }
            auto one = upper_bound(v.begin(),v.end(),a);
            // auto two = lower_bound(v.begin(),v.end(),b);
           
          
             if(one == v.end()){
                ans.push_back(true);
                continue;
            }
              int val = *one;
          if(val>b)ans.push_back(true);
          else ans.push_back(false);
        }
        return ans;
    }
};
using ll  = long long;
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        ll ans=0;int n= nums.size();
        unordered_map<int,int>map;
        ll x = 0;
        map[0]=1;
        for(int i=0;i<n;i++){
            x^=nums[i];
            if(map.count(x))ans+=map[x];
            map[x]++;
        }
        return ans;
    }
};
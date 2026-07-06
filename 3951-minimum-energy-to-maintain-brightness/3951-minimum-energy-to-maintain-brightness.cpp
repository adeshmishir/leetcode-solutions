using ll = long long;
class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        ll ans=0;
        ll s = intervals[0][0];
        ll e = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
             if(intervals[i][0]<=e){
                 e = max(e,1LL*intervals[i][1]);
            }
            else{
                ans+=(e-s+1);
                s = intervals[i][0];
                e= intervals[i][1];
            }
        }
         ans+=(e-s+1);
         ll val = (brightness+2) /3;
         return ans*val;
    }
};
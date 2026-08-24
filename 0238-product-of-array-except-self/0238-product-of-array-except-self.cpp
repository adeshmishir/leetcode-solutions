using ll = long long;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<ll>pref(n+1,1),suff(n+1,1);
        for(int i=0;i<n;i++){
            pref[i+1] = pref[i]*nums[i];
        }
        for(int i=n-1;i>0;i--){
            suff[i-1] = suff[i]*nums[i];
           ;
        }
        for(int i=0;i<n;i++){
            
            cout<<suff[i]<<" ";
        }
        vector<int>ans(n,1);
        for(int i=0;i<n;i++){
            ans[i]=pref[i]*suff[i];
        }
return ans;
    }
};
using ll = long long;
class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
     ll ans = 0;
     int n = nums.size();
     stack<int>st;
     for(int i=0;i<nums.size();i++){
        if(s[i]=='1'){
          int val= 0;
          if(!st.empty()){
            val=st.top();
            st.pop();
          }
          if(!val){
            ans+=nums[i];
          }
          else{
            ans+=(max(val,nums[i]));
            st.push(min(val,nums[i]));
          }
        }
        else{
            st.push(nums[i]);
        }
     }
     return ans;
    }
};
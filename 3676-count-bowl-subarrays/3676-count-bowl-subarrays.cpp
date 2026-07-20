using ll = long long;
class Solution {

public:
    long long bowlSubarrays(vector<int>& nums) {
        stack<int>s;
        long long ans = 0;
        int n  =nums.size();
        // s.push(nums[0]);
        for(int i=0;i<n;i++){
            ll cnt = -1;
            while(!s.empty() &&nums[i]>s.top()){
                s.pop();
                cnt++;
            }
            if(!s.empty() && cnt!=-1)cnt+=1;
          if(cnt!=-1)  ans+=cnt;
            s.push(nums[i]);
        }
        return ans;
    }
};
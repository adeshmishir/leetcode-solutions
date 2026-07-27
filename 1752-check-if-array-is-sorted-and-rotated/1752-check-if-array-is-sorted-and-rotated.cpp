class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0;int n = nums.size();
        int mini = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                if( nums[n-1]>mini)return false;
                cnt++;
            }
            mini = min(nums[i],mini);
        }
        return cnt<=1 ;
    }
};
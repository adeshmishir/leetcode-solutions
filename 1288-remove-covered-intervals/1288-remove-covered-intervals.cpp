class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int s = nums[0][0];
        int e = nums[0][1];
        int ans=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i][0]==s){
                e = max(e,nums[i][1]);
            }
            else if(nums[i][1]>e){
                s=nums[i][0];
                e=nums[i][1];
                ans++;
            }
        }
        return ans;
    }
};
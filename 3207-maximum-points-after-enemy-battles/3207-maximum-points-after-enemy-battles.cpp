class Solution {
public:
    long long maximumPoints(vector<int>& nums, int energy) {
        long long sum = energy;
        int mini = *min_element(nums.begin(),nums.end());
        if(sum<mini)return 0;
        for(auto it:nums){
            sum+=it;
        }
        
        sum-=mini;
        return sum/(mini*1LL);
    }
};
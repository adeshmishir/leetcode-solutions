class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 0;
        int ans=0;
        int sum=0;
       
        unordered_map<int,int>map;
        map[0]=-1;
        for(int i=0;i<nums.size();i++){
           if(nums[i])sum+=1;
           else sum-=1;
           if(map.count(sum))ans=max(ans,i-map[sum]);
           else map[sum]=i;
        }
        // if(sum==0)return n;
        return ans;
    }
};
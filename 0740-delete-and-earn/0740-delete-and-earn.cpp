class Solution {
    int solve(int i,int &maxi,unordered_map<int,int>&map,vector<int>&dp){
        if(i>maxi)return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i]= max(solve(i+1,maxi,map,dp),map[i]+solve(i+2,maxi,map,dp));
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        int sum=nums[0];
        int maxi = nums[0];
        unordered_map<int,int>map;
        for(int i=1;i<n;i++){
            maxi=max(maxi,nums[i]);
            if(nums[i]!=nums[i-1]){
                map[nums[i-1]]=sum;
                sum=0;
            }
            sum+=nums[i];
        }
        
        vector<int>dp(maxi+1,-1);
        map[nums[n-1]]=sum;
        for(auto it:map){
            cout<<it.first<< " "<<it.second<<endl;
        }
        
        return solve(0,maxi,map,dp);
    }
};
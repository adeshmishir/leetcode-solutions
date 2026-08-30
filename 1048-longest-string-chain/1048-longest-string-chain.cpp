class Solution {
    int solve(string s, unordered_map<string,int>&map,vector<int>&dp){
        if(dp[map[s]]!=-1)return dp[map[s]];
        int ans = 0;
        int n = s.size();
        for(int i=0;i<=n;i++){
            string a = s.substr(0,i);
            string b = "";
            if(i!=n)b=s.substr(i,n-i);
            for(char ch='a';ch<='z';ch++){
                string final = a+ch+b;
                if(map.find(final)!=map.end()){
                    ans=max(ans,solve(final,map,dp));
                }
            }
        }
        return dp[map[s]]= ans+1;
    }
public:
    int longestStrChain(vector<string>& nums) {
        unordered_map<string,int>map;
        
        int n = nums.size();
        vector<int>dp(n,-1);
        for(int i=0;i<n;i++){
            map[nums[i]]=i;
        }
        int ans=0;
       for(int i=0;i<n;i++){
        ans =max(ans,solve(nums[i],map,dp));
       }
       return ans;
    }
};
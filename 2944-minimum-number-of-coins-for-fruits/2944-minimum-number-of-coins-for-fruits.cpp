class Solution {
    int solve(int i,int free,vector<int>& prices,vector<vector<int>>&dp){
        if(i==prices.size())return 0;
        if(dp[i][free]!=-1)return dp[i][free];
        if(free){
            return dp[i][free]= min(solve(i+1,free-1,prices,dp),prices[i]+solve(i+1,i+1,prices,dp));
        }
        else{
            return dp[i][free]= prices[i]+(solve(i+1,i+1,prices,dp));
        }
    }
public:
    int minimumCoins(vector<int>& prices) {
        // unordered_map<int,bool>map;
        int n =  prices.size();
        // vector<int>ans;
        // for(int i=0;i<prices.size();i++){
        //     if(!map[prices[i]]){
        //         map[prices[i]]=true;
        //         ans.push_back(prices[i]);
        //     }
        // }
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,0,prices,dp);
    }
};
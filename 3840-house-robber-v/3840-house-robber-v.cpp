using ll = long long;

class Solution {
    vector<vector<ll>> dp;

    ll solve(int i, int col, vector<int>& nums, vector<int>& colors) {
        if (i == nums.size()) return 0;

        if (dp[i][col] != -1) return dp[i][col];

        if (colors[i] == col) {
            return dp[i][col] = solve(i + 1, 0, nums, colors);
        }

        ll take = nums[i] + solve(i + 1, colors[i], nums, colors);
        ll skip = solve(i + 1, 0, nums, colors);

        return dp[i][col] = max(take, skip);
    }

public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
       
       ll take = nums[0];
       ll notTake = 0;
       for(int i=1;i<n;i++){
        ll newNotTake = max(take,notTake);
        ll newTake;
        if(colors[i]==colors[i-1]){
            newTake = nums[i]+notTake;
        }
        else{
            newTake = max(take,notTake)+nums[i];
        }
        take  = newTake;
        notTake = newNotTake;
       }
       return max(take,notTake);
    }
};
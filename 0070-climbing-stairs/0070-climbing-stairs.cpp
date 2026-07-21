class Solution {
public:
    int climbStairs(int n) {
        int a =1;
        if(n==1)return 1;
        int b =2;
        int cnt=2;
        while(cnt<n){
            cnt++;
            int c = a+b;
            a=b;
            b=c;
        }
        return b;
        // vector<int>dp(n+1,0);
        // dp[2]=2;
        // dp[1]=1;
        // for(int i=3;i<=n;i++){
        //     dp[i]=dp[i-1]+dp[i-2];
        // }
        // return dp[n];
    }
};
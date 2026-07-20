class Solution {
    bool check(long long n,int x){
        if(n%10!=x)return false;
        
        while(n>=10){
          
            n/=10;
        }
        return n==x;
    }
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int cnt=0;
        
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
              
                if(check(sum,x))cnt++;

            }
        }
        return cnt;
    }
};
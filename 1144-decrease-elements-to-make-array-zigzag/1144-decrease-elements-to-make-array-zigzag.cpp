class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
       
        int n=nums.size();
        if(n==1){
            return 0;
        }
        int sum1=0;
        int sum2=0;
        bool check=false;
        for(int i=0;i<n;i+=2){
            if(i==0)continue;
            if(i==n-1){
                check=true;
                continue;
            }
            sum1+=(max(0,nums[i]-(min(nums[i-1],nums[i+1])-1)));
        }
        sum1+=(max(0,nums[0]-nums[1]+1));
        if(check){
            sum1+=(max(0,nums[n-1]-nums[n-2]+1));
        }
        cout<<sum1<<endl;
        check=false;
        for(int i=1;i<n;i+=2){
            if(i==n-1){
                check=true;
                continue;
            }
            sum2+=(max(0,nums[i]-(min(nums[i-1],nums[i+1])-1)));
        }
        if(check){
            sum2+=(max(0,nums[n-1]-nums[n-2]+1));
        }
        cout<<sum2<<endl;
        return min(sum1,sum2);
    }
};
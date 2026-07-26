class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();int a=1000000007;
       
        for(int i=0;i<n-2;i++){
            if(nums[i]==nums[i+1]&&nums[i]==nums[i+2]){
                  nums[i]=a;
            }
        }
        sort(nums.begin(),nums.end());
        int ans=0;
    
  for(int i=0;i<n;i++){
    if(nums[i]!=a)ans++;
  }
return ans;

    }
};
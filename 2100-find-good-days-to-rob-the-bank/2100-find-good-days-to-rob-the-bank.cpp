class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int time) {
        int n = nums.size();
        vector<int>left(n,0),right(n,0);
        int cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                cnt++;
            }
            else{
                cnt=0;
            }
            left[i]=cnt;
        }
      cnt=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1]){
                cnt++;
            }
            else{
                cnt=0;
            }
            right[i]=cnt;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(left[i]>=time && right[i]>=time)ans.push_back(i);
        }
        return ans;
    }
};
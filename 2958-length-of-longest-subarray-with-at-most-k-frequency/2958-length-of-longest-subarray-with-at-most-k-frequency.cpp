class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0;
        int ans=0;
        unordered_map<int,int>map;
        while(j<n){
            map[nums[j]]++;
            while(map[nums[j]]>k){
                map[nums[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
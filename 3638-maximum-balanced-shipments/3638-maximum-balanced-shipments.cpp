class Solution {
public:
    int maxBalancedShipments(vector<int>& nums) {
        int n = nums.size();
        // stack<int> s;
        int ans = 0;
        // for (int i = 0; i < n; i++) {
        //     while (!s.empty() && nums[i] > s.top()) {
        //         s.pop();
        //     }
        //     if (s.empty())
        //         ans++;
        //     s.push(nums[i]);
        // }
        int i=0;
        while(i<n-1){
            if(nums[i]>nums[i+1]){
                ans++;
                i++;
            }
            i++; 
        }
        return ans;
    }
};
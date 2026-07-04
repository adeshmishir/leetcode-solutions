class Solution {

    bool check(long long val, long long len, vector<vector<int>>& nums){
        int n = nums.size();
        long long sum = 0;
        int j = 0;

        for(int i = 0; i < n; i++){
            long long start = nums[i][0];
            long long end = start + len - 1;

            while(j < n && nums[j][1] <= end){
                sum += nums[j][1] - nums[j][0] + 1;
                j++;
            }

            long long curr = sum;

            if(j < n && nums[j][0] <= end){
                curr += end - nums[j][0] + 1;
            }

            if(curr >= val) return true;

            sum -= nums[i][1] - nums[i][0] + 1;
        }

        return false;
    }

public:

    int maximumWhiteTiles(vector<vector<int>>& nums, int carpetLen) {
        sort(nums.begin(), nums.end());

        long long lo = 0;
        long long ans = 0;
        long long hi = carpetLen;

        while(lo <= hi){
            long long mid = lo + (hi - lo) / 2;

            if(check(mid, carpetLen, nums)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        return ans;
    }
};
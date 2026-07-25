class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = 2*nums.size();
        if(n==2 || n==4)return n/2;
        int cnt = 0;
        while(n!=0){
            cnt++;
            n/=2;
        }
        return pow(2,cnt-1);
    }
};
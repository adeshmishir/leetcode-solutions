class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        int mini = 1;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(arr[i]<mini)mini=arr[i];
            arr[i]=mini;
            mini+=1;
        }
        return arr[n-1];
    }
};
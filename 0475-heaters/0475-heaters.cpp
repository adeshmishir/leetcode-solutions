class Solution {
public:
    int findRadius(vector<int>& house, vector<int>& heaters) {
        int ans=0;
        int j=0;
        int n = heaters.size();
        int m = house.size();
        sort(house.begin(),house.end());
        sort(heaters.begin(),heaters.end());
        for(int i=0;i<house.size();i++){
            while(j<n && heaters[j]<house[i]){
                j++;
            }
            if(j==n){
                ans=max(ans,house[m-1]-heaters[j-1]);
                break;
            }
            int a=INT_MAX;int b=INT_MAX;
            if(j-1>=0)a=abs(house[i]-heaters[j-1]);
            b = abs(house[i]-heaters[j]);
            ans = max(ans,min(a,b));
        }
        return ans;
    }
};
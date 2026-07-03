class Solution {
public:
    int findWinningPlayer(vector<int>& arr, int k) {
        int n  =arr.size();
        int cnt=0;
        int winner = arr[0];
        int ans=0;
        for(int i=1;i<n;i++){
            
            if(arr[i]>winner){
                winner=arr[i];
                cnt=1;
                ans=i;
                 if(cnt==k)return ans;
            }
            else{
                cnt++;
                if(cnt==k)return ans;
            }
           
        }
        return ans;

    }
};
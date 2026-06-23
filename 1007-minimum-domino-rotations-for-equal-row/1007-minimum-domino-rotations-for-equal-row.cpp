class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int ans=INT_MAX;
        for(int i=1;i<=6;i++){
            bool check=true;
            int cnt=0;
            for(int j=0;j<n;j++){
                if(tops[j]!=i && bottoms[j]==i)cnt++;
                if(tops[j]!=i&& bottoms[j]!=i){
                    check=false;
                    break;
                }
            }
            if(check)ans = min(ans,cnt);
        }
             for(int i=1;i<=6;i++){
            bool check=true;
       int  cnt=0;
            for(int j=0;j<n;j++){
                if(bottoms[j]!=i && tops[j]==i)cnt++;
                if(bottoms[j]!=i&& tops[j]!=i){
                    check=false;
                    break;
                }
            }
            if(check)ans = min(ans,cnt);
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};
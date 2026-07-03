class Solution {
public:
    bool winnerOfGame(string s) {
        int n = s.size();
        int a=0,b=0;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                cnt++;
                if(cnt>=3){
                    if(s[i]=='A')a++;
                    else b++;
                }
            }
            else cnt=1;
        }
        return a>b;
    }
};
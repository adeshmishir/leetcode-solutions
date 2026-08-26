class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i=0;
        int j=0;
        string ans (100,'1');
        if(s==ans)return s.substr(0,k);
        int cnt=0;
        int n = s.size();
        while(j<n){
            if(s[j]=='1'){
                cnt++;
            }
            while((cnt==k) &&   (s[i]=='0')){
                i++;
            }

            if(cnt==k){
                string p =  s.substr(i,j-i+1);
            if((j-i+1)<ans.size()){
                ans = p;
            }
            else if ((j-i+1)==ans.size()){
                if(p<ans)ans=p;
            }
            i++;
            cnt--;
            }
            j++;
        }
        if(ans.size()==100)return "";
return ans;
    }
};
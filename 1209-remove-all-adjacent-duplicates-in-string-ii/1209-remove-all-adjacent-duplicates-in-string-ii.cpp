class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
       string ans = "";
       for(int i=0;i<n;i++){
        ans+=s[i];
        if(ans.size()>=k){
            int sz = ans.size();
            string temp = ans.substr(sz-k,k);
            bool check=true;
            for(int j=1;j<k;j++){
                if(temp[j]!=temp[j-1]){
                    check=false;
                    break;
                }
            }
            if(check)ans.erase(sz-k,k);
        }
       }
        return ans;
    }
};
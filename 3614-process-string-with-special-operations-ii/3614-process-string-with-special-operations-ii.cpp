using ll = long long;
class Solution {

public:
    char processStr(string s, long long k) {
      int n = s.length();
      vector<ll>lens;
      ll len=0;
      for(char ch:s){
        if(ch=='*')len = max(len-1,0LL);
        else if(ch=='#')len*=2;
        else if(ch!='%')len++;
            
        lens.push_back(len);
      }
      if(k>=len)return '.';
      for(int i=n-1;i>=0;i--){
        if(s[i]=='*')continue;
        else if(s[i]=='#'){
            if(k>=lens[i]/2)k-=lens[i]/2;
        }
        else if(s[i]=='%')k=lens[i]-1-k;
        else if(lens[i]==k+1)return s[i];
      }
      return '.';
    }
};
class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int ans = 0;int val=k;
        // for True
        int i=0;int j=0;
        int n = s.size();
        while(j<n){
              if(s[j]=='F')k--;
              while(k<0){
                if(s[i]=='F')k++;
                i++;
              }
              ans = max(ans,j-i+1);
              j++;
        }

        // for false;
k=val;
        i=0;j=0;
         while(j<n){
              if(s[j]=='T')  k--;
                while(k<0){
                if( s[i]=='T')k++;  
                i++;
               }
              ans = max(ans,j-i+1);
              j++;
        }
return ans;
    }
};
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt=0;
      
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')cnt++;
            else if(s[i]==')'){
                if(cnt){
                    cnt--;  
                }
                else {
                    s.erase(i,1);
                    i--;
                }
            
            }
       
        }
        cnt=0;
         for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')')cnt++;
            else if(s[i]=='('){
                if(cnt){
                    cnt--;
                   
                }
                else {
                    s.erase(i,1);
                }
            
            }
       
        }
       return s;
    }
};
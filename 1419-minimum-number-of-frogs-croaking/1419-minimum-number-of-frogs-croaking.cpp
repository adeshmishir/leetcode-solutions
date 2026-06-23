class Solution {
public:
    int minNumberOfFrogs(string s) {
        int ans=0;
        int cnt=0;
        int c=0,r=0,o=0,a=0,k=0;
        
        for(char ch:s){
            if(ch=='c')c++;
            else if(ch=='r'){
                r++;
                if(c<r)return -1;
            }
            else if(ch=='o'){
                o++;
                if(c<0 || r<o)return -1;
            }
            else if(ch=='a'){
                a++;
                if(c<a || r<a || o<a)return -1;
            }
            else if(ch=='k'){
                k++;
                if(c<k || r<k || o<k || a<k)return -1;
            }
            else return -1;
        }
        if(c!=o || c!=a ||c!=r|| c!=k)return -1;
        
        
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='c')cnt++;
            else if(s[i]=='k')cnt--;
            ans = max(ans,cnt);
        }
        return ans;
    }
};
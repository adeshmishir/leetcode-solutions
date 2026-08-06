class Solution {
    bool isPal(string s){
        int i = 0;int j= s.length()-1;
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;j--;
        }
        return true;
    }
public:
    string smallestPalindrome(string s) {
        // sort(s.begin(),s.end());
        // while(next_permutation(s.begin(), s.end())){
        //     if(isPal(s))return s;
        // }
        // return s;
        vector<int>v(26,0);
        for(auto &c:s){
            v[c - 'a']++;
        }
        int i=0;
        int j = s.length()-1;
        int ch;
        for(int p=0;p<26;p++){
            if(v[p]&1)ch=p;
            while(v[p]>1){
                s[i]=('a' +p);
                s[j]=('a' +p);
                i++;j--;
                v[p]-=2;
            }
        }
        if(i<j){
            s[i+1]=('a'+ch);
        }
        return s;
    }
};
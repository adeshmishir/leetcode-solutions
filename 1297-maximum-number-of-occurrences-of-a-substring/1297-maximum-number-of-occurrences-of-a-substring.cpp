class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();unordered_map<string,int>map;
        int ans=0;
        for(int sz=minSize;sz<=maxSize;sz++){
            unordered_map<char,int>freq;
            int i=0;
            int j=0;
            
            while(j<n){
                 freq[s[j]]++;
                if( j-i+1<sz){
                    j++;
                    continue;
                }
               
                while(freq.size()>maxLetters ||j-i+1>sz){
                    freq[s[i]]--;
                    if(freq[s[i]]==0)freq.erase(s[i]);
                    i++;
                }
                if(j-i+1==sz){
                    map[s.substr(i,sz)]++;
                    ans = max(ans,map[s.substr(i,sz)]); 
                }
                j++;
            
            }
        }
        return ans;
        
    }
};
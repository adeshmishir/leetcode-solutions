class Solution {
public:
    vector<int> partitionLabels(string s) {
       vector<int>ans;
       unordered_map<char,int>map,res; 
       for(char c:s){
        map[c]++;
       }
       int a = 0,prev=-1;
       for(int i=0;i<s.length();i++){
        
             if(res[s[i]]==0){
                res[s[i]]=1;
                a++;
             }
             map[s[i]]--;
             if(map[s[i]]==0){
                a--;
                if(a==0){
                    ans.push_back(i-prev);
                    prev=i;
                    res.clear();
                }
             }
           

       }
       return ans;
    }
};
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string>map;
        for(auto &it:knowledge){
            map[it[0]]=it[1];
        }
        int n = s.size();
        string temp="";
        string ans="";
        bool check=false;
        for(int i=0;i<n;i++){
            if(s[i]=='(')check=true;
            else if(s[i]==')'){
                    if(map.count(temp))ans+=map[temp];
                    else ans+='?';
                    temp="";
                    check=false;
            }
            if(check && s[i]!='(')temp+=s[i];
            else if(!check && s[i]!=')') ans+=s[i];
        }
        return ans+temp;

    }
};
class Solution {
    void solve(int i,int n,int k,string temp, vector<string>&ans){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        if(k<i || (temp.size()>0 && temp[temp.size()-1]=='1')){
            temp.push_back('0');
            solve(i+1,n,k,temp,ans);
        }
        else{
            temp.push_back('0');
            solve(i+1,n,k,temp,ans);
            temp.pop_back();
            temp.push_back('1');
            solve(i+1,n,k-i,temp,ans);
        }
    }
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string>ans;
        solve(0,n,k,"",ans);
        return ans;
    }
};
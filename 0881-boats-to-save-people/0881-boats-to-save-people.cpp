class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        int i=0;int n = people.size();
        int j = n-1;
        sort(people.begin(),people.end());
        while(i<=j){
            ans++;
            if(i==j){
                i++;
                continue;
            }
            int sum = people[i]+people[j];
            if(sum>limit){
                j--;
            }
            else{
                i++;
                j--;
            }
        }
        return ans;

    }
};
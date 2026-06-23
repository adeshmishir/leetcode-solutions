class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> sequential;

for (int start = 1; start <= 9; start++) {
    int num = start;

    for (int nxt = start + 1; nxt <= 9; nxt++) {
        num = num * 10 + nxt;

        if (num >= 10 && num <= 1000000000)
            sequential.push_back(num);
    }
}

sort(sequential.begin(), sequential.end());
vector<int>ans;
for(int i=0;i<sequential.size();i++){
    if(sequential[i]>=low && sequential[i]<=high){
        ans.push_back(sequential[i]);
    }
}
return ans;
    }
};
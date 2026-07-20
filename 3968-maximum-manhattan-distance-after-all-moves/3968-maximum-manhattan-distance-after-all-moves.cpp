class Solution {
public:
    int maxDistance(string moves) {
        int a = 0;
        int b  =0;
        int c = 0;
        for(auto ch:moves){
            if(ch=='U')a++;
            else if(ch=='D')a--;
            else if(ch=='R')b++;
            else if(ch=='L')b--;
            else c++;
        }
        return abs(a)+abs(b)+c;
    }
};
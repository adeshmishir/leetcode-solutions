class Solution {
    int solve(int lo,int hi){
        if(lo>=hi)return 0;
        int mid = lo + (hi-lo)/2;
        return 1 + max(solve(lo,mid),solve(mid+1,hi));
    }
public:
    int twoEggDrop(int n) {
        // return solve(0,n);
       for(int i=0;i<100;i++){
        int val = (i*(i+1))/2;
        if(val>=n)return i;
       }
       return 0;
    }
};
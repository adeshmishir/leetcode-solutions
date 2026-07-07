class Solution {
public:
    int minOperations(int n) {
         int ans=0;
        if(n&1){
            int val = 2*(n/2);
           
            while(val){
                ans+=val;
                val-=2;
            }
          
        }
        else{
            int val = n-1;
          
            while(val>0){
ans+=val;
val-=2;
            }
          
        }
        return ans;
    }
};
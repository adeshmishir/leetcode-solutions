class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int ans=0;
       
        for(auto ch:s){
            if(ch=='('){
                st.push(0);
            }
            else{
                int score = 0;
                while(!st.empty() && st.top()>0){
                    score+=st.top();
                    st.pop();
                }
                st.pop();
                score*=2;
                if(score==0)score=1;
                    
                
                st.push(score);
               
               }
            
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
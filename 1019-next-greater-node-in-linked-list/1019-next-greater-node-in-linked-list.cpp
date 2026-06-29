/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reversed(ListNode* head){
        if(!head)return NULL;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp){
            ListNode* node = temp->next;
            temp->next=prev;
            prev=temp;
            temp=node;
        }
      
        return prev;
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp = reversed(head);
     
      vector<int>ans;
     
     stack<int>st;
        while(temp){

            while(!st.empty() && st.top()<=temp->val){
                st.pop();
            }
            int val=-1;
            if(!st.empty())val = st.top();
            st.push(temp->val);
            //   if(temp->val==st.top()){
            //     maxi = temp->val;
            //   }
              if(st.size()==1)ans.push_back(0);
              else ans.push_back(val);
              temp=temp->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
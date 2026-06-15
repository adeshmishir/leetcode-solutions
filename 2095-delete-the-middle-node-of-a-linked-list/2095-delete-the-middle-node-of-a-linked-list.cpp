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
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL)return NULL;

        int size=0;
        ListNode* temp=head;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        if(size==1)return NULL;
        if(size==2){
            ListNode* ans=new ListNode(head->val);
            return ans;
        }
        temp=head;int k=size/2;
        while(k>1){
            temp=temp->next;
            k--;
        }
        ListNode* system=temp->next;
        if(system&&system->next){
             temp->next=system->next;
        }
       

        return head;
    }
};
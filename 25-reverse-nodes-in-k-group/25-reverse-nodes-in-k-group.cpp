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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* l=head;
        ListNode* r=head;
        ListNode* t=NULL;
        ListNode* temp=new ListNode();
        t=temp;
        ListNode* t2=NULL;
        while(r!=NULL)
        {
            int n=k-1;
            while(r->next!=NULL && n)
            {
                r=r->next;
                n--;
            }
            if(n==0)
            {
                t2=r->next;
                r->next=NULL;
            }
            else
                break;
            
            ListNode* current=l;
            ListNode* next=NULL;
            ListNode* prev=NULL;
            ListNode* t1=NULL;
            while(current!=NULL)
            {
                next=current->next;
                current->next=prev;
                prev=current;
                current=next;
        
                if(t1==NULL)
                    t1=prev;
            }
            t->next=prev;
            t1->next=t2;
            t=t1;
            l=t2;
            r=t2;
        }
        return temp->next;
    }
};
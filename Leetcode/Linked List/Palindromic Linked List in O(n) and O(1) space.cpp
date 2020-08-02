/*
https://leetcode.com/problems/palindrome-linked-list/
*/
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
    bool isPalindrome(ListNode* head) {
        ListNode* tmp=head;
        int n=0;
        while(tmp!=NULL)
        {
            tmp=tmp->next;
            n++;
        }
        
        if(n==1)
            return true;
        
        int ct=0;
        ListNode* l=NULL;
        tmp=head;
        while(tmp!=NULL)
        {
            ct++;
            ListNode* tmp2=tmp->next;
            tmp->next=l;
            l=tmp;
            tmp=tmp2;
            if(ct==(n/2))
            {
                break;
            }
        }
        
        ListNode* mid=tmp,*l1=l;
        
        if(n&1)
        {
            tmp=tmp->next;
        }
        int ok=1;
        ListNode* r=tmp;
        while(l!=NULL&&r!=NULL)
        {
            if(l->val!=r->val)
            {
                ok=0;
                break;
            }
            r=r->next;
            l=l->next;
        }
        l=l1;
        while(l!=NULL)
        {
            ListNode *t=l->next;
            l->next=mid;
            mid=l;
            l=t;    
        }
        return ok;
    }
};

/*
https://leetcode.com/problems/middle-of-the-linked-list/
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
    ListNode* middleNode(ListNode* head) {
     
        if(head==NULL)
            return head;
        if(head->next==NULL)
            return head;
        if((head->next)->next==NULL)
            return head->next;
        
        ListNode* tmp1=head;
        ListNode* tmp2=head->next;
        
        while(1)
        {
            if(tmp1->next!=NULL&&tmp2->next!=NULL)
            {
                tmp1=tmp1->next;
                tmp2=tmp2->next;
                if(tmp2->next!=NULL)
                {
                    tmp2=tmp2->next;
                    continue;
                }
                return tmp1;
            }
            return tmp1->next;
        }
        
        return head;
        
    }
};

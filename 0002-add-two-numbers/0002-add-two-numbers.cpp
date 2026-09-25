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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode(0);
        ListNode *Head=ans;
        int first=0,second=0,carry=0,sum=0,rem=0;
        while(l1 && l2)
        {
            first=l1->val;
            second=l2->val;

            sum=first+second+carry;
            rem=sum%10;
            carry=sum/10;
            ListNode *temp=new ListNode(rem);
            ans->next=temp;
            ans=ans->next;
            l1=l1->next;
            l2=l2->next;

        }

        while(l1)
        {
            first=l1->val;
            sum=carry+first;
            rem=sum%10;
            carry=sum/10;
            ListNode *temp=new ListNode(rem);
            ans->next=temp;
            ans=ans->next;
            l1=l1->next;
        }

        while(l2)
        {
            second=l2->val;
            sum=carry+second;
            rem=sum%10;
            carry=sum/10;
            ListNode *temp=new ListNode(rem);
            ans->next=temp;
            ans=ans->next;
            l2=l2->next;
        }
        while(carry)
        {
            rem=carry%10;
            ListNode *temp=new ListNode(rem);
            ans->next=temp;
            ans=ans->next;
            carry=carry/10;
        }
        return Head->next;
    }
};
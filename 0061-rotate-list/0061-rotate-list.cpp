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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        int length=1;
        ListNode* temp=head;
        while(temp->next)
        {
            temp=temp->next;
            length++;
        }
        temp->next=head;
        length=length-(k%length);
        temp=head;
        length--;
        while(length)
        {
            length--;
            temp=temp->next;
        }
        ListNode* newHead=temp->next;
        temp->next = NULL;
        return newHead;
    }
};
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>critical;
        int i=1;
        ListNode* prev=head;
        ListNode* curr=head->next;

        while(curr->next!=nullptr)
        {
            ListNode* next=curr->next;

            if((curr->val>prev->val && curr->val>next->val)|| (curr->val < prev->val && curr->val < next->val))
            {
                critical.push_back(i);
            }
            prev=curr;
            curr=next;
            i++;
        }
        if(critical.size()<2)
        {
            return {-1,-1};
        }
        int minDist=INT_MAX;
        int maxDist=critical.back()-critical.front();

        for(int j=1;j<critical.size();j++)
        {
            minDist=min(minDist,critical[j]-critical[j-1]);
        }

        return {minDist,maxDist};
    }
};
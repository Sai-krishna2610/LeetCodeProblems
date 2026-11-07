/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void getMin(TreeNode* root,int &prev, int &ans)
    {
        if(!root)
        {
            return;
        }
        getMin(root->left,prev,ans);
        if(prev!=INT_MIN)
        {
            ans=min(ans,root->val-prev);
        }
        prev = root->val;
        getMin(root->right,prev,ans);
        return;
    }

    int getMinimumDifference(TreeNode* root) {
        int prev=INT_MIN;
        int ans=INT_MAX;
        getMin(root,prev,ans);
        return ans;
    }
};
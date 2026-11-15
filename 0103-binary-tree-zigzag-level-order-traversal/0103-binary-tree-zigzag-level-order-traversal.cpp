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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
        {
            return {};
        }
        TreeNode* temp=root;
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        st1.push(root);
        vector<vector<int>>ans;
        bool leftToright=true;
        while(!st1.empty() || !st2.empty())
        {
            
            if(leftToright){
                int n=st1.size();
                vector<int>level;
                for(int i=0;i<n;i++)
                {
                    TreeNode* temp=st1.top();
                    level.push_back(temp->val);

                    st1.pop();
                    if(temp->left)
                    {
                        st2.push(temp->left);
                    }
                    if(temp->right)
                    {
                        st2.push(temp->right);
                    }
                }
                ans.push_back(level);
                leftToright=false;
            }
            else
            {
                int n=st2.size();
                vector<int>level;
                for(int i=0;i<n;i++)
                {
                    TreeNode* temp=st2.top();
                    level.push_back(temp->val);

                    st2.pop();
                    if(temp->right)
                    {
                        st1.push(temp->right);
                    }

                    if(temp->left)
                    {
                        st1.push(temp->left);
                    }
                }
                ans.push_back(level);
                leftToright=true;
            }
        }
        return ans;
    }
};
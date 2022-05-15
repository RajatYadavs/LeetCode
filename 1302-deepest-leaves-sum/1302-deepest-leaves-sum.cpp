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
int levelOrder(TreeNode* root)
{
    queue<TreeNode*>q;
    q.push(root);
    
    int sum;
    while(!q.empty())
    {
        int n=q.size();
        sum=0;
        for(int i=0;i<n;i++)
        {
            TreeNode* t=q.front();
            q.pop();
            sum+=t->val;
            if(t->left!=NULL)
                q.push(t->left);
            if(t->right!=NULL)
                q.push(t->right);
        }
    }
    return sum;
}
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        return levelOrder(root);
    }
};
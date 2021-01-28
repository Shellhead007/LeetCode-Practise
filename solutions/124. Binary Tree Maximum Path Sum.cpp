/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root)  {
        int res = INT_MIN;
        
        findmax(root,res);
        return res;
    }
private:
    int findmax(TreeNode* root,int &res) {
        if(root==NULL)
            return 0;
        
        int ls = findmax(root->left,res);
        int rs = findmax(root->right,res);
        
        int max_single = max(root->val,max(ls,rs)+root->val);
        int max_top = max(max_single,ls+rs+root->val);
        res = max(res,max_top);
        return max_single;
    }
};

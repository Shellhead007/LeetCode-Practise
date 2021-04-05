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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)
            return -1;
        int ans = dfs(root,root->val);
        return ans;
    }
    private:
        int dfs(TreeNode* root,int minval) {
        if(!root)
            return -1;
        if(root->val != minval)
            return root->val;
        int left = dfs(root->left,minval);
        int right = dfs(root->right,minval);
        if(left == -1)
            return right;
        if(right == -1)
            return left;
        return min(left,right);
    }
};

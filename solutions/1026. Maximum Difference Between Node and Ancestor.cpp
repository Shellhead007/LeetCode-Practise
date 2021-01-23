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
    int maxAncestorDiff(TreeNode* root) {
        return Ans(root,INT_MAX,0);
    }
private:
    int Ans(TreeNode* root,int mn,int mx) {
        if(root == NULL)
            return abs(mx-mn);
        mx = max(mx,root->val);
        mn = min(mn,root->val);
        return max(Ans(root->left,mn,mx),Ans(root->right,mn,mx));
    }
};

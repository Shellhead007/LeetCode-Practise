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
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        return Valid(root, LONG_MIN, LONG_MAX);
        
    }
    bool Valid(TreeNode* root, long min_val, long max_val) {
        if(!root)
            return true;
        if(root->val <= min_val || root->val >= max_val)
            return false;
        return Valid(root->left, min_val, root->val) && Valid(root->right, root->val, max_val);
        
    }
};

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
    int max_depth = 0;
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        max_depth = depth(root);
        return deepUtil(root,0);
    }
private :
    int depth(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(depth(root->left),depth(root->right));
    }    
    int deepUtil(TreeNode* root, int d) {
        if(!root) return 0;
        if(d == max_depth - 1) return root->val;
        return deepUtil(root->left,d+1)+deepUtil(root->right,d+1); 
    }
};

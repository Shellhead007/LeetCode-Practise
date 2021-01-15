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
    int ans = 0;
    int goodNodes(TreeNode* root) {
        maxNode(root,INT_MIN);
        return ans;
    }
private:
    void maxNode(TreeNode* root, int maximum) {
        if(!root)
            return;
        if(root->val >= maximum) {
            ans++;
            maximum = root->val;
        }
        maxNode(root->left,maximum);
        maxNode(root->right,maximum);
    }
};

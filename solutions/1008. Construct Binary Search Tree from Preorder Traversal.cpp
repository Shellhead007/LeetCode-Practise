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
    int preindex;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        preindex = 0;
        TreeNode* root = bstUtil(preorder,INT_MAX);
        return root;
    }
public:
    TreeNode* bstUtil(vector<int>& preorder,int bound) {
        if(preindex == preorder.size() || preorder[preindex] > bound)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preindex++]);
        root->left = bstUtil(preorder,root->val);
        root->right = bstUtil(preorder,bound);
        return root;
    }
};

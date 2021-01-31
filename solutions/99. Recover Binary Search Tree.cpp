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
TreeNode* firstElement;
TreeNode* secondElement;
TreeNode* prevElement;
public:
    void recoverTree(TreeNode* root) {
        if(!root)
            return;
        firstElement = NULL;
        secondElement = NULL;
        prevElement = NULL;
        Inorder(root);
        long int temp = firstElement->val;
        firstElement->val = secondElement->val;
        secondElement->val = temp;
    }
private:
    void Inorder(TreeNode* root) {
        if(!root)
            return;
        Inorder(root->left);
        // will do something here
        if(firstElement==NULL && (prevElement == NULL || prevElement->val >= root->val))
            firstElement = prevElement;
        if(firstElement!=NULL && prevElement->val >= root->val)
            secondElement = root;
        prevElement = root;
        Inorder(root->right);
    }
};

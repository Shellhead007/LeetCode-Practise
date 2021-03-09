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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1) {                       // Base case
            TreeNode* new_node = new TreeNode(v);
            new_node->left = root;
            return new_node;
        }
        dfs(root,v,d-1,1);  // we will check till level d-1.
        return root;
    }
private:
    void dfs(TreeNode* root,int v,int mlvl,int clvl) {
        if(!root)
            return;
        if(mlvl == clvl) {        // when we reached level d-1, we will make 2 new nodes and properly assign the nodes to their respective positions
            TreeNode* temp1 = new TreeNode(v);
            TreeNode* temp2 = new TreeNode(v);
            temp1->left = root->left;
            temp2->right = root->right;
            root->left = temp1;
            root->right = temp2;
            return;
        }
        dfs(root->left,v,mlvl,clvl+1);
        dfs(root->right,v,mlvl,clvl+1);
    }
};

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
    int answer;
    int maxPathSum(TreeNode* root)  {     // Best explanation for this problem by Errichto 
        answer = INT_MIN;                 // https://www.youtube.com/watch?v=bm0q6huoriY  
        dfs(root);
        return answer;
    }
private:
    int dfs(TreeNode* root) {
        if(!root)
            return 0;
        int x = dfs(root->left);
        int y = dfs(root->right);
        answer = max(answer,x+y+root->val);
        return max(0,root->val + max(x,y));
    }
};

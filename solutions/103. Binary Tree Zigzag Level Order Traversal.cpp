 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> >res;
        if(!root)
            return res;
        stack<TreeNode*> CL;
        stack<TreeNode*> NL;
        vector<int>ans;
        bool lefttoright = true;
        CL.push(root);
        while(!CL.empty()) {
            TreeNode* temp = CL.top();
            CL.pop();
            if(temp) {
                ans.push_back(temp->val);
                if(lefttoright) {
                    if(temp->left)
                        NL.push(temp->left);
                    if(temp->right)
                        NL.push(temp->right);
                } else {
                    if(temp->right)
                        NL.push(temp->right);
                    if(temp->left)
                        NL.push(temp->left);
                }
            }
             
            if(CL.empty()) {
                res.push_back(ans);
                lefttoright = !lefttoright;
                swap(CL,NL);
                ans = {};
            }
        }
        return res;
    }
};

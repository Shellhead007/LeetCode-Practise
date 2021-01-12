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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>r1,r2;
        inorder(root1,r1);
        inorder(root2,r2);
        vector<int>res(r1.size()+r2.size());
        if(root1 == NULL && root2 == NULL)
            return res;
        if(root1==NULL)
            return r2;
        if(root2 == NULL)
            return r1;
        merge(r1,r2,res);
        return res;
    }
private :
    void inorder(TreeNode* root,vector<int>& r) {
        if(root) {
            inorder(root->left,r);
            r.push_back(root->val);
            inorder(root->right,r);
        }
    }
    void merge(vector<int>& r1,vector<int>& r2,vector<int>& res) {
        int n1 = r1.size();
        int n2 = r2.size();
        int i = 0,j = 0, k = 0;
        while(i < n1 && j < n2) {
            if(r1[i] < r2[j]) {
                res[k] = r1[i];
                i++;
            }
            else {
                res[k] = r2[j];
                j++;
            }
            k++;
        }
        while(i < n1) {
            res[k] = r1[i];
            i++;k++;
        }
        while(j < n2) {
            res[k] = r2[j];
            j++;k++;
        }
    }
};

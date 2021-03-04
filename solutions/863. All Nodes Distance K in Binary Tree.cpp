/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void nodeskdistance(TreeNode* target, int K, vector<int> &ans){
    if(target==NULL){
        return;
    }
    if(K==0){
        ans.push_back(target->val);
        return;
    }
    nodeskdistance(target->left, K-1, ans);
    nodeskdistance(target->right, K-1, ans);
}
bool findNode(TreeNode* root, TreeNode* target, int &K, vector<int> &ans){
    if(root==NULL){
        return false;
    }
    if(root==target){
        nodeskdistance(target, K, ans);
        return true;
    }
    bool ifleft = findNode(root->left, target,K, ans);
    bool ifright = findNode(root->right, target, K, ans);
    if(ifleft){
        --K; // decrese the distance now as parent will be at 1 distance now from the target.
        if(K<0){
            return true; //if the ancestor is more than k distance away from the parent
        }
        if(K==0){
            ans.push_back(root->val);
            return true;
        }
        nodeskdistance(root->right, K-1, ans); //search in right subtree for nodes at a distance k
        return true;
    }
    if(ifright){
        --K;
        if(K<0){
            return true; //if the ancestor is more than k distance away from the parent
        }
        if(K==0){
            ans.push_back(root->val);
            return true;
        }
        nodeskdistance(root->left, K-1, ans); //search in left subtree for nodes at a distance k
        return true;
    }
    return false;
}
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> ans;
        findNode(root, target, K, ans);
        return ans;
    }
};

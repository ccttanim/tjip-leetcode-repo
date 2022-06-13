/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, int& i, int k){
        if(root == NULL){
            return NULL;
        }
        TreeNode* left = solve(root->left, i, k);
        if(left != NULL){
            return left;
        }
        i++;
        if(i == k){
            return root;
        }
        return solve(root->right, i, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ind = 0;
        TreeNode* ans = solve(root, ind, k);
        int res = ans->val;
        return res;
    }
};

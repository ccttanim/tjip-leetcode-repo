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
    TreeNode* constructBST(vector<int>&nums, int L, int R)
    {
        if(L > R) return NULL;
        int M = L + (R - L) / 2;
        TreeNode* curr = new TreeNode(nums[M]);
        curr->left = constructBST(nums,L,M-1);
        curr->right = constructBST(nums,M+1,R);
        return curr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructBST(nums, 0, nums.size() - 1);
    }
};

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
    int maxSum = INT_MIN;

    int solve(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        int l = solve(root-> left);
        int r = solve(root->right);

        int any_one_good = max(l, r) + root->val;
        int root_good = root->val;
        int found_below = root->val + l + r;

        maxSum = max({maxSum, any_one_good, root_good, found_below});

        return max(any_one_good, root_good);
    }
    int maxPathSum(TreeNode* root) {
        int ans = solve(root);
        return maxSum;
    }
};

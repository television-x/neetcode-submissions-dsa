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
    bool dfs(TreeNode* root, long long lower, long long upper){
        // base case
        if (!root){
            return true;
        }

        bool a = true, b = true;

        if (root->val <= lower || root->val >= upper){
            return false;
        }

        if (root->left) {
            if (root->left->val >= root-> val){
                return false;
            }

            a = dfs(root->left, lower, root->val); // max(upper, root->val)
        }

        if (root->right) {
            if (root->right->val <= root->val){
                return false;
            }

            b = dfs(root->right, root->val, upper);
        }

        return a && b;

    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
};

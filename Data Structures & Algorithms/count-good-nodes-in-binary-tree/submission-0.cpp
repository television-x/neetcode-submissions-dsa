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


 /*
 
            2
          /   \
         1     1
        /     / \ 
       3     1   5
 
 */

class Solution {
public:
    int good = 0;

    void dfs(TreeNode* root, int value){
        if (!root){
            return;
        }

        if (root->val >= value)
        {
            good += 1;
        }

        if (root->left){
            dfs(root->left, max(root->val, value));
        }

        if (root->right){
            dfs(root->right, max(root->val, value));
        }

    }
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);

        return good;
    }
};

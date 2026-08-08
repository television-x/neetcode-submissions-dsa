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
#define pb push_back
class Solution {
public:
    vector<int> result;
    void inOrder(TreeNode* root){
        if (root == NULL)   return;
        inOrder(root->left);
        result.pb(root->val);
        inOrder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root);
        sort(result.begin(), result.end());
        return result[k-1];
    }
};

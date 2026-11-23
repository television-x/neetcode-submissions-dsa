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
    TreeNode* function(vector<int>& preorder, vector<int>& inorder, int start, int end , int &idx) {
        if (start > end){
            return nullptr;
        }

        int rootval = preorder[idx];
        int i = start;

        for (; i <= end; ++i){
            if(inorder[i] == rootval)
                break;
        }

        idx++;

        TreeNode* root = new TreeNode(rootval);

        root->left  = function(preorder, inorder, start, i-1, idx);
        root->right = function(preorder, inorder, i+1, end, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int idx = 0;
        return function(preorder, inorder, 0, n-1, idx);
    }
};

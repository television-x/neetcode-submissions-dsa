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
    void solve(TreeNode* node, vector<vector<int>> &result){
        if (!node)  return;
        queue<TreeNode*> q;
        q.push(node);
        int count = 0;
        while(!q.empty()){
            int n = q.size();
            result.push_back(vector<int>());
            while(n--){
                node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                result[count].push_back(node->val);
            }
            count++;
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        solve(root, result);
        return result;

    }
};

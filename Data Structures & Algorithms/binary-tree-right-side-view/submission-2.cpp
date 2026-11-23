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
 
 at every level i will maintain a list and i will pop the last one

        1
      /   \        -> level 0
    2       3       -> level 1 
      \ 
        4
    

    1, 3, 4
 */

class Solution {
public:
    vector<int> result;

    vector<int> rightSideView(TreeNode* root) {

        if (!root){
            return {};
        }

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            
            while(n--) {
                auto s = q.front();
                q.pop();

                if (n == 0){
                    result.push_back(s->val);
                }

                if (s->left){
                    q.push(s->left);
                }
                if (s->right){
                    q.push(s->right);
                }
            }
        }

        return result;
    }
};

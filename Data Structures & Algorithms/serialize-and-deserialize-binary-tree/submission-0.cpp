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

class Codec {
private:
    void preorder(TreeNode* root, string& s) {
        if (!root) {
            s += "#,";
            return;
        }
        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    TreeNode* build(vector<string>& tokens, int& idx) {
        string t = tokens[idx++];
        if (t == "#") return nullptr;

        TreeNode* root = new TreeNode(stoi(t));   // stoi handles negatives
        root->left  = build(tokens, idx);
        root->right = build(tokens, idx);
        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        stringstream ss(data);
        string item;
        while (getline(ss, item, ',')) {
            tokens.push_back(item);
        }

        int idx = 0;
        return build(tokens, idx);
    }
};

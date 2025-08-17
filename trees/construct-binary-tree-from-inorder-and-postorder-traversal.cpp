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
    unordered_map<int, int> pos;
    int postIdx; // class member

    TreeNode* build(vector<int>& post, int l, int r) {
        if (l > r) return nullptr;

        int val = post[postIdx--];
        TreeNode* root = new TreeNode(val);

        int idx = pos[val];
        // Build right subtree first for postorder
        root->right = build(post, idx + 1, r);
        root->left = build(post, l, idx - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) 
            pos[inorder[i]] = i;

        postIdx = postorder.size() - 1;
        return build(postorder, 0, inorder.size() - 1);
    }
};

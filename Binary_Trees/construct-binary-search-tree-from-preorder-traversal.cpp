/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int idx = 0;

    TreeNode* build(vector<int>& preorder, int upper) {
        if (idx == preorder.size() || preorder[idx] > upper) 
            return NULL;

        int val = preorder[idx++];
        TreeNode* root = new TreeNode(val);
        root->left = build(preorder, val);   // left subtree values < val
        root->right = build(preorder, upper); // right subtree values < upper
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }
};

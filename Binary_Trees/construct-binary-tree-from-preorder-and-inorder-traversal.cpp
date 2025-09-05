class Solution {
public:
    unordered_map<int, int> pos; 
    int preIdx = 0;

    TreeNode* build(vector<int>& pre, int l, int r) {
        if (l > r) return nullptr;

        int val = pre[preIdx++];
        TreeNode* root = new TreeNode(val);

        int idx = pos[val];
        root->left = build(pre, l, idx - 1);
        root->right = build(pre, idx + 1, r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) pos[inorder[i]] = i;
        return build(preorder, 0, inorder.size() - 1);
    }
};

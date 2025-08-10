class Solution {
public:
    int maxi = INT_MIN;

    int solve(TreeNode* root) {
        if (!root) return 0;

        // Compute max path sum of left and right, ignoring negatives
        int l = max(0, solve(root->left));
        int r = max(0, solve(root->right));

        // Update global maximum with path passing through root
        maxi = max(maxi, root->val + l + r);

        // Return best single path to parent
        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
};

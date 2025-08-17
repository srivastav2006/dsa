class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int v = root->val;
        int pval = p->val;
        int qval = q->val;

        if(pval < v && qval < v) {
            // both nodes are in left subtree
            return lowestCommonAncestor(root->left, p, q);
        } 
        else if(pval > v && qval > v) {
            // both nodes are in right subtree
            return lowestCommonAncestor(root->right, p, q);
        } 
        else {
            // nodes are on different sides OR one is equal to root
            return root;
        }
    }
};

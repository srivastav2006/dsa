class Solution {
public:
    bool check(TreeNode* l, TreeNode* r) {
        if (l == NULL || r == NULL) 
            return l == r; // Both null → true, one null → false
        
        return (l->val == r->val) &&
               check(l->left, r->right) &&
               check(l->right, r->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return check(root->left, root->right);
    }
};

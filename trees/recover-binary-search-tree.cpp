class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *na = nullptr, *nb = nullptr, *pa = nullptr, *cr = root;

        while (cr) {
            if (cr->left == nullptr) {
                if (pa && pa->val > cr->val) {
                    if (!na) na = pa;
                    nb = cr;
                }
                pa = cr;
                cr = cr->right;
            } else {
                TreeNode* pr = cr->left;
                while (pr->right && pr->right != cr) {
                    pr = pr->right;
                }
                if (!pr->right) {
                    pr->right = cr;
                    cr = cr->left;
                } else {
                    pr->right = nullptr;
                    if (pa && pa->val > cr->val) {
                        if (!na) na = pa;
                        nb = cr;
                    }
                    pa = cr;
                    cr = cr->right;
                }
            }
        }
        if (na && nb) swap(na->val, nb->val);
    }
};

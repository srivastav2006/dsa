class Solution {
public:
    int height(TreeNode* root, int &dia) { // pass dia by reference
        if (!root) return 0;
        
        int l = height(root->left, dia);
        int r = height(root->right, dia);
        
        dia = max(dia, l + r); // update diameter
        return 1 + max(l, r);  // return height
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        height(root, dia);
        return dia;
    }
};

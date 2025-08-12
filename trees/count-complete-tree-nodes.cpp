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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int lh = 0, rh = 0;
        TreeNode *l = root, *r = root;
        
        // Calculate left height
        while (l) {
            lh++;
            l = l->left;
        }
        
        // Calculate right height
        while (r) {
            rh++;
            r = r->right;
        }
        
        // If left and right heights are equal => it's a perfect tree
        if (lh == rh) {
            return (1 << lh) - 1;
        }
        
        // Otherwise, recursively count
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

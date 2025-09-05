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

class BSTIterator {
private:
    stack<TreeNode*> st;
    bool forward; // true -> normal inorder, false -> reverse inorder

    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            node = forward ? node->left : node->right;
        }
    }

public:
    BSTIterator(TreeNode* root, bool isForward) {
        forward = isForward;
        pushAll(root);
    }

    int next() {
        TreeNode* node = st.top(); st.pop();
        if (forward) pushAll(node->right);
        else pushAll(node->left);
        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        BSTIterator l(root, true);   // left → right
        BSTIterator r(root, false);  // right → left

        int i = l.next();
        int j = r.next();

        while (i < j) {
            if (i + j == k) return true;
            else if (i + j < k) {
                if (l.hasNext()) i = l.next();
                else break;
            } else {
                if (r.hasNext()) j = r.next();
                else break;
            }
        }
        return false;
    }
};

// Memory efficiency:

// Hash set = O(n) memory → bad for very large BSTs.

// Iterators = O(h) memory → only need stack of height. For balanced BST, this is O(log n).

// Streaming traversal:

// Iterators don’t need the whole tree stored first; they generate values on the fly.

// This is important if the tree is huge (millions of nodes).

// Faster in practice:

// No hash lookups.

// Each node is visited at most once, and comparisons are simple integer additions.
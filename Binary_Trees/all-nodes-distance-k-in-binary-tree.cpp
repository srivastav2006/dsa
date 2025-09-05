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
    unordered_map<TreeNode*, TreeNode*> parent; // store parent for each node
    unordered_set<TreeNode*> visited; // to avoid revisiting

    void dfs(TreeNode* node, TreeNode* par) {
        if (!node) return;
        parent[node] = par;
        dfs(node->left, node);
        dfs(node->right, node);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, nullptr); // fill parent mapping

        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);

        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            if (dist == k) break; // we reached required distance
            dist++;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // explore neighbors: left, right, parent
                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if (parent[node] && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};

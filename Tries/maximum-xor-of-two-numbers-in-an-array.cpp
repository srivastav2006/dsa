class Solution {
    struct Node {
        Node* children[2]; // only 0 and 1
        Node() {
            children[0] = children[1] = nullptr;
        }
    };

    void insert(Node* root, int num) {
        Node* cur = root;
        for (int i = 31; i >= 0; i--) {   // 32-bit numbers
            int bit = (num >> i) & 1;     // extract i-th bit
            if (!cur->children[bit]) {
                cur->children[bit] = new Node();
            }
            cur = cur->children[bit];
        }
    }

    int query(Node* root, int num) {
        Node* cur = root;
        int xorVal = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;   // we want the opposite bit for max XOR
            if (cur->children[opposite]) {
                xorVal |= (1 << i);   // set this bit in result
                cur = cur->children[opposite];
            } else {
                cur = cur->children[bit]; // no choice, follow same bit
            }
        }
        return xorVal;
    }

public:
    int findMaximumXOR(vector<int>& nums) {
        Node* root = new Node();

        // Step 1: Insert all numbers
        for (int num : nums) {
            insert(root, num);
        }

        // Step 2: Find maximum XOR
        int maxXor = 0;
        for (int num : nums) {
            maxXor = max(maxXor, query(root, num));
        }

        return maxXor;
    }
};

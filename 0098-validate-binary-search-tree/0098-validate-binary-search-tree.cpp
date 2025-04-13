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
private:
    bool inOrder(TreeNode* node) {
        if (!node) return true;

        // Left subtree
        if (!inOrder(node->left)) return false;

        // Current node must be greater than previous
        if (prev && node->val <= prev->val) return false;

        prev = node;

        // Right subtree
        return inOrder(node->right);
    }
public:
    TreeNode* prev = nullptr;

    bool isValidBST(TreeNode* root) {
        return inOrder(root);
    }

};

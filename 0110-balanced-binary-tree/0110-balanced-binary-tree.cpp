class Solution {
private:
    pair<bool, int> dfs(TreeNode* root) {
        // pair = balanced and height
        if (!root) return {true, 0};
        
        auto [leftBalanced, leftHeight] = dfs(root->left);
        auto [rightBalanced, rightHeight] = dfs(root->right);
        
        bool isBalanced = leftBalanced && rightBalanced && abs(leftHeight - rightHeight) <= 1;
        
        return {isBalanced, 1 + max(leftHeight, rightHeight)};
    }

public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;        
    }
    
};
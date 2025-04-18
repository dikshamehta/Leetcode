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
    int globalSum;
    void solve(TreeNode* root, int localSum){
        if(!root){
            return;
        }

        localSum = localSum * 10 + root->val;

        if(root->left == nullptr && root->right == nullptr){
            globalSum += localSum;
            return;
        }

        solve(root->left, localSum);
        solve(root->right, localSum);

    }
    int sumNumbers(TreeNode* root) {
        solve(root, 0);
        return globalSum;    
    }
};
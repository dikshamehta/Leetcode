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
    void dfs(TreeNode* root, int& k, int& ans){
        if(root == NULL){
            return;
        }

        // if(k==1){
        //     ans = root->val;
        //     return;
        // }

        dfs(root->left, k, ans);

        k--;
        if(k==0){
            ans = root->val;
            return;
        }
        cout<<root->val;
        dfs(root->right, k, ans);

    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        dfs(root, k, ans);
        return ans;
    }
};
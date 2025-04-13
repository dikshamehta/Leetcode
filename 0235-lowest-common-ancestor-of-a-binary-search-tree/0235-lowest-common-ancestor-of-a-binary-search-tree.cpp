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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root!= NULL){
            //Since BST if both are smaller than root go left
            if(p->val<root->val && q->val<root->val){
                root = root->left;
            }
            else if(p->val>root->val && q->val>root->val){
                root = root->right;
            }
            else{
                // one of them is smaller and one is greater or equal
                // then this is the solution
                return root;
            }
        }
        return nullptr;
    }
};
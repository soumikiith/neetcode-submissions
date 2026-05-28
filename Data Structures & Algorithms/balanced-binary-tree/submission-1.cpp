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
    int hd(TreeNode *node){
        if(node == nullptr)
            return 0;
        int left = hd(node->left);
        int right = hd(node->right);

        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        int h_l = hd(root->left);
        int h_r = hd(root->right);

        if( abs(h_l - h_r) >1 )
            return false;
        else
            return isBalanced(root->left) && isBalanced(root->right);
    }
};

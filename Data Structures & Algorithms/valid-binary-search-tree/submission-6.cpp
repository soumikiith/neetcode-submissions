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
    vector<int> t;
    void Inorder(TreeNode *node){
        if(node == nullptr)
            return;
        Inorder(node->left);
        t.push_back(node->val);
        Inorder(node->right);
    }
    bool isValidBST(TreeNode* root) {
        Inorder(root);
        if(t.empty()){
            return true;
        }
        else{
            for(int i=0; i<t.size()-1;i++){
                if(t[i]>=t[i+1])
                    return false;
            }
        }
        return true;
    }
};

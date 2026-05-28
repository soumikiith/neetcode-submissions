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
    int kthSmallest(TreeNode* root, int k) {
        
        queue<TreeNode*> q;
        priority_queue<int> pq;
        q.push(root);

        while(! q.empty()){
            TreeNode *front_elem = q.front();
            q.pop();

            pq.push(front_elem->val);
            if(pq.size()>k){
                pq.pop();
            }
            if(front_elem->left)
                q.push(front_elem->left);
            if(front_elem->right)
                q.push(front_elem->right);
        }

        return pq.top();
    }
};

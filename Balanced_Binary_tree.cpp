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
    int height(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        if(left == -1){return -1;};
        if(right == -1){return -1;};
        
        int val{right-left};
        if(val < 0){
            val*=-1;
        }
        if(val > 1){
            return -1;
        }
        if(left > right){
            return 1+ left;
        }
        return 1+ right;
    }
    bool isBalanced(TreeNode* root) {
        //depth of two subtrees must never be more than 1
        return height(root) !=-1;
    }
};
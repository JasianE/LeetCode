/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //Base case, the node itself is the descendant
        bool right_of_p{root->val > p->val};
        bool right_of_q{root->val > q->val}; 

        while(right_of_p == right_of_q){
            if(root == p || root == q){
                return root;
            }
            if(root->val > p->val){
                root = root->left;
                right_of_p = root->val >= p->val;
                right_of_q = root->val >= q->val; 
            } else {
                root = root->right;
                right_of_p = root->val >= p->val;
                right_of_q = root->val >= q->val; 
            }
        }
        return root;
    }
};
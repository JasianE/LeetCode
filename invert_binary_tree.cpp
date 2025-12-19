

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //Recursively call to switch the left node to the right node
        if(!root){
            return root;
        }
        if(root->left != nullptr || root->right != nullptr){
            TreeNode* tmp{root->left};
            root->left = root->right;
            root->right = tmp;
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};
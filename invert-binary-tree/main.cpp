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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* left = root->right;
        TreeNode* right = root->left;
        root->left = left;
        root->right = right;

        if (root->left != nullptr) {
            invertTree(root->left);
        }

        if (root->right != nullptr) {
            invertTree(root->right);
        }

        return root;
    }
};

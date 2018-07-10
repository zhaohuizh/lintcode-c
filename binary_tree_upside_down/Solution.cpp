/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
private:
    TreeNode* newRoot = nullptr;
    TreeNode* helper(TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->left == nullptr) {
            assert(node->right == nullptr);
            newRoot = node;
            return node;
        }
        TreeNode* par = helper(node->left);
        par->left = node->right;
        par->right = node;
        node->left = nullptr;
        node->right = nullptr;
        return node;
    }
public:
    /**
     * @param root: the root of binary tree
     * @return: new root
     */
    TreeNode * upsideDownBinaryTree(TreeNode * root) {
        helper(root);
        return newRoot;
    }
};

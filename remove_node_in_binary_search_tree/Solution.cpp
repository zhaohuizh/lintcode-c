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
    TreeNode* findMaxLeft(TreeNode* node) {
        assert(node && node->left);
        TreeNode* cur = node->left;
        while(cur->right) {
            cur = cur->right;
        }
        return cur;
    }
    void deleteNode(TreeNode* cur, TreeNode* par) {
        if (cur->left == nullptr && cur->right == nullptr) {
            if (par->left == cur) {
                par->left = nullptr;
            }
            if (par->right == cur) {
                par->right = nullptr;
            }
        } else if (cur->left == nullptr) {
            if (par->left == cur) {
                par->left = cur->right;
            }
            if (par->right == cur) {
                par->right = cur->right;
            }
        } else if (cur->right == nullptr) {
            if (par->left == cur) {
                par->left = cur->left;
            }
            if (par->right == cur) {
                par->right = cur->left;
            }
        } else {
           TreeNode* maxLeft = findMaxLeft(cur);
           swap(cur->val, maxLeft->val);
           cur->left = removeNode(cur->left, maxLeft->val);
        }
    }
public:
    /*
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode * removeNode(TreeNode * root, int value) {
        TreeNode dummy(INT_MAX);
        dummy.left = root;

        TreeNode* node = root;
        TreeNode* par = &dummy;
        while (node) {
            if (node->val == value) {
                deleteNode(node, par);
                break;
            } else if (node->val < value) {
                par = node;
                node = node->right;
            } else {
                par = node;
                node = node->left;
            }
        }
        return dummy.left;
    }
};

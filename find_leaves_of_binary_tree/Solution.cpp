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
    void mergeRes(vector<vector<int>>& leftRes,
            vector<vector<int>>& rightRes, vector<vector<int>>& res) {
        int i = 0, j = 0;
        int sizeL = leftRes.size(), sizeR = rightRes.size();
        while (i < sizeL && j < sizeR) {
            vector<int> left = leftRes[i];
            vector<int> right = right[i];
            vector<int> combine;
            for (int l : left) {
                combine.push_back(l);
            }
            for (int r : right) {
                combine.push_back(r);
            }
            res.push_back(combine);
            i++;
            j++;
        }

        while (i < sizeL) {
            vector<int> left = leftRes[i];
            vector<int> combine;
            for (int l : left) {
                combine.push_back(l);
            }
            res.push_back(combine);
            i++;
        }
        while (j < sizeR) {
            vector<int> right = right[i];
            vector<int> combine;
            for (int r : right) {
                combine.push_back(r);
            }
            res.push_back(combine);
            j++;
        }
    }
public:
    /*
     * @param root: the root of binary tree
     * @return: collect and remove all leaves
     */
    vector<vector<int>> findLeaves(TreeNode * root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        vector<vector<int>> leftRes = findLeaves(root->left);
        vector<vector<int>> rightRes = findLeaves(root->right);
        mergeRes(leftRes, rightRes, res);
        vector<int> last;
        last.push_back(root->val);
        res.push_back(last);
        return res;
    }
};

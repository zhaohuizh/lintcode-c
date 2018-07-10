#include<vector>
#include<queue>
#include<string>
#include<sstream>

#include <stdlib.h> 
#include <iostream>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};


class Solution {
private:
    vector<string> split(const string &str, string delim) {
        vector<string> results;
        int lastIndex = 0, index;
        while ((index = str.find(delim, lastIndex)) != string::npos) {
            results.push_back(str.substr(lastIndex, index - lastIndex));
            lastIndex = index + delim.length();
        }

        if (lastIndex != str.length()) {
            results.push_back(str.substr(lastIndex, str.length() - lastIndex));
        }
        return results;
    }
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode * root) {
        stringstream ss;
        if (root == NULL) return ss.str();
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        for (int i = 0; i < nodes.size(); ++i) {
            if (nodes[i] == NULL) {
                ss << ",#";
                continue;
            }   
            ss << "," <<  nodes[i]->val;
            nodes.push_back(nodes[i]->left);
            nodes.push_back(nodes[i]->right);
        }
        string s = ss.str();
        return s.substr(1, s.size());
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) {
        if (data == "") return NULL;
        vector<string> vals = split(data, ",");
        bool left = true;
        queue<TreeNode*> queue;
        TreeNode *cur = new TreeNode(atoi(vals[0].c_str()));
        queue.push(cur);
        for(int i = 1; i < vals.size(); i++) {
            if (vals[i] != "#") {
                TreeNode* node = new TreeNode(atoi(vals[i].c_str()));
                if (left) {
                    queue.front()->left = node;
                } else {
                    queue.front()->right = node;
                }
                queue.push(node);
            }
            if (!left) {
                queue.pop();
            }
            left = !left;
        }
    }
};

int main() {
    TreeNode* node = new TreeNode(1);
    TreeNode* right = new TreeNode(2);
    node->right = right;
    Solution* s = new Solution();
    string str = s->serialize(node);
    cout << str << endl;
    TreeNode* cur = s->deserialize(str);
}

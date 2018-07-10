#include<string>
#include<assert.h>
#include<vector>

using namespace std;

class Solution {
private:
    void dfs(string& num, int target, vector<string>& res, int start, int last, string expression, int sum) {
        int len = num.size();
        if (start == len) {
            if (sum == target) {
                res.push_back(expression);
            }
            return;
        }
        for(int i = start; i < len; i++) {
            int cur = stoi(num.substr(start, i + 1));
            //第一个数字特殊处理
            if (start == 0) {
                assert(sum == 0);
                dfs(num, target, res, i + 1, cur, "" + to_string(cur), cur);
            } else {
                dfs(num, target, res, i + 1, cur, expression + "+" + to_string(cur), sum + cur);
                dfs(num, target, res, i + 1, cur, expression + "-" + to_string(cur), sum - cur);
                dfs(num, target, res, i + 1, cur * last, expression + "+" + to_string(cur), sum - last + last * cur);
            }
            
        }
    }
public:
    /**
     * @param num: a string contains only digits 0-9
     * @param target: An integer
     * @return: return all possibilities
     */
    vector<string> addOperators(string &num, int target) {
        vector<string> res;
        dfs(num, target, res, 0, 0, "", 0);
        return res;
    }
};

int main() {
    Solution s;
    string str("123");
    s.addOperators(str, 6);
    return 1;
}

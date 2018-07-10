#include <vector>
#include <utility>
#include <string>
#include <cmath>
using namespace std;

class Solution {
private:
    bool valid(vector<pair<int, int> >& queens) {
        for (int i = 0; i < queens.size() - 1; i++) {
            for (int j = i + 1; j < queens.size(); j++) {
                if (abs(queens[i].first - queens[j].first) ==
                        abs(queens[i].second - queens[j].second)) {
                    return false;
                }
            }
        }
        return true;
    }
    void helper(int n, vector<vector<string> >& res, vector<string> candidate, vector<bool>& flags, vector<pair<int, int> >& queens) {
        if (candidate.size() == n) {
            res.push_back(candidate);
            return;
        }
        int y = candidate.size();
        for (int i = 0; i < n; i++) {
            if (flags[i]) continue;
            queens.push_back(make_pair(i, y));
            if (valid(queens)) {
                flags[i] = true;
                string one ('.',n);
                one[i] = 'Q';
                candidate.push_back(one);
                helper(n, res, candidate, flags, queens);
                flags[i] = false;
            }
            queens.pop_back();
        }
    }

public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> candidate;
        vector<bool> x_axile(n, false);
        vector<pair<int, int> > queens;
        helper(n, res, candidate, x_axile, queens);
        return res;
    }
};
int main() {
    Solution* s = new Solution();
    s->solveNQueens(2);
}

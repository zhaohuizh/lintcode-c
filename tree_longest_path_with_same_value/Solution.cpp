#include <unordered_map>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
private:
    int result = 0;
    /**
     * @return longest path with same value with me and include me
     */
    int helper(vector<int> &A, vector<vector<int>>& nums, int cur) {
        // Use tmp vector and sort to get the first and second longest
        vector<int> tmp;
        for (int i = 0; i < nums[cur].size(); i++) {
            int paths = helper(A, nums, nums[cur][i]);
            if(A[cur - 1] == A[nums[cur][i] - 1]) {
                tmp.push_back(paths + 1);
            }
        }
        // Add two dummy element for better handling of sort and select the beginning two
        tmp.push_back(0);
        tmp.push_back(0);
        sort(tmp.begin(), tmp.end());
        result = max(result, tmp[tmp.size() - 1] + tmp[tmp.size() - 2]);
        return tmp.back();
    }
public:
    /**
     * @param A: as indicated in the description
     * @param E: as indicated in the description
     * @return: Return the number of edges on the longest path with same value.
     */
    int LongestPathWithSameValue(vector<int> &A, vector<int> &E) {
        vector<vector<int>> nums(A.size() + 1);
        for (int i = 0; i < E.size(); i = i + 2) {
            nums[E[i]].push_back(E[i + 1]);
            nums[E[i + 1]].push_back(E[i]);
        }
        helper(A, nums, 1);
        return result;
    }
};

int main() {
    Solution* s = new Solution();
    vector<int> org;
    org.push_back(1);
    org.push_back(1);
    org.push_back(1);
    org.push_back(1);
    org.push_back(1);
    vector<int> one;
    one.push_back(1);
    one.push_back(2);
    one.push_back(1);
    one.push_back(3);
    one.push_back(2);
    one.push_back(4);
    one.push_back(2);
    one.push_back(5);

    int ret = s->LongestPathWithSameValue(org, one);
    cout << ret << endl;
}

#include <map>
#include <vector>
using namespace std;


class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: return a list of integers
     */
    vector<int> countSmaller(vector<int> &nums) {
        int m = nums.size();
        vector<int> res (m, 0);
        map<int, int> map;
        for (int i = m - 1; i >= 0; i--) {
            auto it = map.lower_bound(nums[i]);
            if (it == map.end()) {
                res[i] = 0;
            } else {
                if (it != map.begin()) {
                    --it;
                }
                res[i] = res[it->second] + 1;
            }
            map[nums[i]] = res[i];
        }
        return res;
    }
};
int main(){
    Solution* s = new Solution();
    vector<int> num;
    num.push_back(5);
    num.push_back(2);
    num.push_back(6);
    num.push_back(1);
    vector<int> res = s->countSmaller(num);
}


#include <string>
#include <vector>
#include <set>
#include <climits>

using namespace std;

class Solution {
private:
    int smallest = INT_MAX;
    string res;
    int getMin(string& time) {
        return ((time[0] - '0') * 10 + time[1] - '0') * 60 + (time[3] - '0') * 10 + time[4] - '0';
    }
    
    void helper(int min, set<int>& digits, int n, int cur) {
        if (n == 1 && cur > 2) return;
        if (n == 2 && cur >= 24) return;
        if (n == 3 && cur % 10 >= 6) return;
        if (n == 4 && cur % 100 >= 60) return;
        if (n == 4) {
            int curMin = cur / 100 * 60 + cur % 100;
            if (curMin < min) {
                curMin += 1440;
            }
            if (curMin < smallest) {
                smallest = curMin;
                res = to_string(cur).insert(2, ":");
            }
            return;
        }
        for (int digit : digits) {
            helper(min, digits, n + 1, cur * 10 + digit);
        } 
    }
    
public:
    /**
     * @param time: the given time
     * @return: the next closest time
     */
    /**
     * 解题思路：列举所有选项并且找到最小值。这也是一种解题思路，并不一定
     * 求最小／最大的值可以有规律可以立刻求得
     */
    string nextClosestTime(string &time) {
        int min = getMin(time);
        set<int> digits;
        digits.insert(time[0] - '0');
        digits.insert(time[1] - '0');
        digits.insert(time[3] - '0');
        digits.insert(time[4] - '0');
        if(digits.size() == 1) return time;
        helper(min, digits, 0, 0);
        return res;
    }
};
int main() {
    string str("05:45");
    Solution s;
    s.nextClosestTime(str);
}

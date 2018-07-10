#include <vector>
#include <iostream>

using namespace std;

/**
 * Definition of Interval:
*/

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};


class Solution {
public:
    /**
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        auto it = intervals.begin();
        while (it != intervals.end() && it->start < newInterval.start) {
            ++it;
        }
        intervals.insert(it, newInterval);
        vector<Interval> res;
        Interval last = intervals[0];
        res.push_back(last);
        for (auto it = intervals.begin() + 1; it != intervals.end(); ++it) {
            if (it->start > last.end) {
                res.push_back(*it);
                last = (*it);
            } else {
                last.end = max(last.end, it->end);
            }
        }
        return res;
    }
};
int main() {
    Solution* s = new Solution();
    vector<Interval> vec;
    Interval interval(1, 5);
    Interval interval2(5,7);
    vec.push_back(interval);
    vector<Interval> ret = s->insert(vec, interval2);
    cout << ret.size();
}

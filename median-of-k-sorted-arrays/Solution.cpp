#include <vector>
#include <climits>

using namespace std;

class Solution {
private:
    int count_num(vector<vector<int>>& nums) {
        int res = 0;
        for (vector<int> num : nums) {
            if (num.empty()) continue;
            res += num.size();
        }
        return res;
    }
    
    int find_min(vector<vector<int>>& nums) {
        int res = INT_MAX;
        for (vector<int> num : nums) {
            if (!num.empty()) {
                res = min(res, num[0]);
            }
        }
        return res;
    }
    
    int find_max(vector<vector<int>>& nums) {
        int res = INT_MIN;
        for (vector<int> num : nums) {
            if (!num.empty()) {
                res = max(res, num[num.size() - 1]);
            }
        }
        return res;
    }
    
    int findKth(vector<vector<int>>& nums, int k) {
        int start = find_min(nums), end = find_max(nums);
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (getGTE(nums, mid) >= k) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (getGTE(nums, start) >= k) {
            return start;
        }
        return end;
    }
    
    // get how many numbers greater than or equal to val in 2d array
    int getGTE(vector<vector<int>>& nums, int val) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += getGTE(nums[i], val);
        }
        return sum;
    }
    
    // get how many numbers greater than or equal to val in an array
    int getGTE(vector<int>& nums, int val) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int start = 0, end = nums.size() - 1;
        
        // find first element >= val 
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= val) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        if (nums[start] >= val) {
            return nums.size() - start;
        }
        
        if (nums[end] >= val) {
            return nums.size() - end;
        }
        
        return 0;
    }
public:
    /**
     * @param nums: the given k sorted arrays
     * @return: the median of the given k sorted arrays
     */
    double findMedian(vector<vector<int>> &nums) {
        if (nums.size() == 0 || nums[0].size() == 0) return 0.0;
        int count = count_num(nums);
        if (count % 2) {
            return findKth(nums, count / 2 + 1);
        } else {
            return (findKth(nums, count / 2) + findKth(nums, count / 2 + 1)) / 2.0;
        }
    }
};
int main() {
    Solution s;
    vector<vector<int>> nums;
    vector<int> one; one.push_back(1);
    nums.push_back(one);
    vector<int> two;
    nums.push_back(two);
    vector<int> three; three.push_back(2);
    nums.push_back(three);
    vector<int> four; four.push_back(3);
    nums.push_back(four);
    vector<int> five; five.push_back(3);
    nums.push_back(five);
    
    double r = s.findMedian(nums);
}

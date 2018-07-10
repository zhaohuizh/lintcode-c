#include<climits>
#include<vector>

using namespace std;

class Solution {
public:
    /**
     * @param arr: The given matrix
     * @return: Return the mininum sum
     */
    long long minimumSubmatrix(vector<vector<int>> &arr) {
        if (arr.size() == 0 || arr[0].size() == 0) {
            return 0;
        }
        long long res = LONG_MAX;
        int m = arr.size(), n = arr[0].size();
        int sum[m + 1][n + 1] = {{0}};
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] +
                        arr[i - 1][j - 1];
                res = min(res, (long long)sum[i][j]);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> arr;
    vector<int> one;
    one.push_back(1);
    one.push_back(1);
    one.push_back(1);
    arr.push_back(one);
    vector<int> two;
    two.push_back(1);
    two.push_back(1);
    two.push_back(1);
    arr.push_back(two);
    vector<int> three;
    three.push_back(1);
    three.push_back(1);
    three.push_back(1);
    arr.push_back(three);
    s.minimumSubmatrix(arr);
}


class Solution {
public:
    /*
     * @param matrix: an integer matrix
     * @return: the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>> &matrix) {
        vector<vector<int>> res;
        if (matrix.size() == 0 || matrix[0].size() == 0) return res;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> presum(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = matrix[i][j] + presum[i][j + 1] +
                    presum[i + 1][j] - presum[i][j];
                presum[i + 1][j + 1] = sum;
            }
        }

        unordered_map<int, int> map;
        for (int i = 0; i < m; i++) {
            for (int k = i + 1; k <= m; k++) {
                map.clear();
                for (int j = 0; j <= n; j++) {
                    int diff = presum[k][j] - presum[i][j];
                    if (map.find(diff) == map.end()) {
                        map[diff] = j; 
                    } else {
                        int s_row = i;
                        int s_col = map[diff];
                        int e_row = k - 1;
                        int e_col = j - 1;
                        vector<int> one;
                        one.push_back(s_row);
                        one.push_back(s_col);
                        res.push_back(one);
                        vector<int> two;
                        two.push_back(e_row);
                        two.push_back(e_col);
                        res.push_back(two);
                        return res;
                    }
                }
            }
        }
    }
};

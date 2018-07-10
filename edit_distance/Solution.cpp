#include<string>
#include<iostream>

using namespace std;
class Solution {
public:
    /**
     * @param word1: A string
     * @param word2: A string
     * @return: The minimum number of steps.
     */
    int minDistance(string &word1, string &word2) {
        int m = word1.size(), n = word2.size();
        if (m == 0) {
            return n;
        }
        if (n == 0) {
            return m;
        }
        int dp[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0) {
                    dp[i][j] = j;
                    continue;
                }
                if (j == 0) {
                    dp[i][j] = i;
                    continue;
                }
                int target = dp[i - 1][j - 1];
                if (word1[i] != word2[j]) {
                    target++;
                }
                dp[i][j] = min(target, dp[i - 1][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
        return dp[m][n];
    }
};
int main() {
    Solution s;
    string str1("sea");
    string str2("ate");
    cout << s.minDistance(str1, str2);
}

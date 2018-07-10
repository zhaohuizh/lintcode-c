#include <vector>
#include <string>
#include <climits>
using namespace std;
class Solution {
private:
    bool palindrom(string& s) {
        int j = s.size() - 1;
        int i = 0;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void find_all_subseqs(string& s, int start, string prefix, vector<string>& subseqs) {
        if (start == s.size()) {
            subseqs.push_back(string(prefix));
            return;
        }
        find_all_subseqs(s, start + 1, prefix, subseqs);
        for (int i = start; i < s.size(); i++) {
            find_all_subseqs(s, i + 1, prefix + s[i], subseqs);
        }
    }
public:
    /**
     * @param s: the maximum length of s is 1000
     * @return: the longest palindromic subsequence's length
     */
    int longestPalindromeSubseq(string &s) {
        vector<string> subseqs;
        find_all_subseqs(s, 0, "", subseqs);
        int res = INT_MIN;
        for (string subseq : subseqs) {
            if (palindrom(subseq)) {
                int size = subseq.size();
                res = max(res, size);
            }
        }
        return res;
    }
};
int main() {
    string str ("cbbd");
    Solution s;
    int ret = s.longestPalindromeSubseq(str);
}

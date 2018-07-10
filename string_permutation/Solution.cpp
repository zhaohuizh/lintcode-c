class Solution {
private:
    void helper(string& str, vector<string>& res, vector<bool>& flags, string candidate) {
        if (candidate.size() == str.size()) {
            res.push_back(candidate);
            return;
        }
        for (int i = 0; i < str.size(); i++) {
            if (flags[i]) {
                continue;
            }
            if (i != 0 && str[i] == str[i - 1] && !flags[i - 1]) {
                continue;
            }
            flags[i] = true;
            helper(str, res, flags, candidate + str[i]);
            flags[i] = false;
        }
    }
public:
    /**
     * @param str: A string
     * @return: all permutations
     */
    vector<string> stringPermutation2(string &str) {
        sort(str.begin(), str.end());
        vector<string> res;
        vector<bool> flags(str.size(), false);
        string candidate;
        helper(str, res, flags, candidate);
        return res;
    }
};

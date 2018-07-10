#include <string>
#include <string.h>
#include <iostream>

using namespace std;
    /*
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        int j = 0, res = 0, count = 0;
        int charset[256] = {0};
        for (int i = 0; i < s.size(); i++) {
            while (j < s.size()) {
                if (charset[s[j]] > 0) {
                    charset[s[j]]++;
                } else if (count == k) {
                    break;
                } else {
                    charset[s[j]]++;
                }
                j++;
            }
            res = max (res, j - i);
            charset[s[i]]--;
            if (charset[s[i]] == 0) {
                count--;
            }
        }
        return res;
    }

int main () {
    string input = string("eceba");
    int res = lengthOfLongestSubstringKDistinct(input, 3);
    std::cout << "result: " << res << endl;
}

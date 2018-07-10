#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

class Solution {
public:
    /**
     * @param pattern: a string, denote pattern string
     * @param str: a string, denote matching string
     * @return: an boolean, denote whether the pattern string and the matching string match or not
     */
    bool wordPattern(string &pattern, string &str) {
        vector<string> words;
        int i = 0;
        while (i < str.size()) {
            int end = str.find(' ', i);
            if (end == string::npos) {
                words.push_back(str.substr(i));
                break;
            }
            words.push_back(str.substr(i, end - i));
            i = end + 1;
        }
        if (pattern.size() != words.size()) return false;
        
        unordered_map<char, string> map;
        for (int i = 0; i < pattern.size(); i++) {
            if (map.find(pattern[i]) == map.end()) {
                map[pattern[i]] = words[i];
            } else if (map[pattern[i]] != words[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string pattern("abba");
    string words("dog cat cat dog");
    Solution s;
    bool res =  s.wordPattern(pattern, words);
    printf("%d", res);
}

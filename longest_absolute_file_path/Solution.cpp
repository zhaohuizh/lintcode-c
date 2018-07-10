#include<string>
#include<stack>
#include<assert.h>

using namespace std;

class Solution {
public:
    /**
     * @param input: an abstract file system
     * @return: return the length of the longest absolute path to file
     */
    int lengthLongestPath(string &input) {
        int res = 0;
        int size = input.size();
        if (size == 0) {
            return res;
        }
    
        stack<int> s;
        int i = 0;
        while (i < size) {
            int tabs = 0;
            while (i < size && input[i] == '\t') {
                tabs++;
                i++;
            }
            assert(tabs <= s.size());
            
            while (s.size() > tabs) {
                s.pop();
            }
            int begin = i;
            while (i < size && input[i] != '\n') {
                i++;
            }
            int len = i - begin;
            if (s.size() > 0) {
                len += s.top() + 1;
            }
            s.push(len);
            res = max(len, res);
            i++;
        }
        return res;
    }
};
int main() {
    Solution s;
    string str ("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext");
    s.lengthLongestPath(str);
    return 1;
}

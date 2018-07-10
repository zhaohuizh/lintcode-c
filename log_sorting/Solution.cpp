#include <string>
#include <vector>
using namespace std;

bool operator < (string str1, string str2) {
    string cont1 = str1.substr(str1.find(" ") + 1);
    string cont2 = str2.substr(str2.find(" ") + 1);
    if (cont2[0] <= '9') return true;
    if (cont1 < cont2) return true;
    if (cont1 > cont2) return false;
    if (str1.substr(0, str1.find(" ")) < str2.substr(0, str2.find(" "))) {
        return true;
    }
    return false;
}

class Solution {
public:
    /**
     * @param logs: the logs
     * @return: the log after sorting
     */
    vector<string> logSort(vector<string> &logs) {
        vector<string> result;
        for (string str : logs) {
            string content = str.substr(str.find(" ") + 1);
            bool digit = content[0] <= '9';
            if (digit || result.size() == 0) {
                result.push_back(str);
                continue;
            }
            
            for (auto it = result.begin(); it < result.end(); it++) {
                if (str < *it) {
                    result.insert(it, str);
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
   vector<string> inputs;
   inputs.push_back("zo4 4 7");
   inputs.push_back("a100 Act zoo");
   inputs.push_back("a1 9 2 3 1");
   inputs.push_back("g9 act car");
   Solution s;
   s.logSort(inputs);
}

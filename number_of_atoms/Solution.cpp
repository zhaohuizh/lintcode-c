#include <string>
#include <map>
#include <string> 
#include <iostream> 
#include <sstream> 

using namespace std;

class Solution {
private:
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
    
    bool isAtom(char c) {
        return c >= 'A' && c <= 'Z';
    }
    
    int getDigit(string& formula, int start, int& end) {
        int i = start;
        for (; i < formula.size(); i++) {
            if (!isDigit(formula[i])) {
                break;
            }
        }
        
        end = i;
        
        if (start == i) {
            return 1;
        }
        return stoi(formula.substr(start, i - start));
    }
    
    string getAtom(string& formula, int start, int& end) {
        int i = start + 1;
        for (; i < formula.size(); i++) {
            if (isAtom(formula[i]) || isDigit(formula[i])) {
                break;
            }
        }
        end = i;
        return formula.substr(start, i - start);
    }
    
    void helper(string& formula, map<string, int>& count) {
        if (formula.size() == 0) {
            return;
        }
        int start = 0, end = 0;
        while (start < formula.size()) {
            if (formula[start] == '(') {
                map<string, int> tmp;
                int idx = formula.find(')');
                string inner = formula.substr(start + 1, idx - start - 1);
                helper(inner, tmp);
                int digit = getDigit(formula, idx + 1, start);
                for (auto it = tmp.begin(); it != tmp.end(); it++) {
                    string str = it->first;
                    int num = it->second;
                    if (count.find(str) == count.end()) {
                        count[str] = num * digit;
                    } else {
                        count[str] += num * digit;
                    }
                }
                continue;
            }
            int end = start;
            string atom = getAtom(formula, start, start);
            int num = getDigit(formula, start, start);
            if (count.find(atom) == count.end()) {
                count[atom] = num;
            } else {
                count[atom] += num;
            }
        }
    }
public:
    /**
     * @param formula: a string
     * @return: return a string
     */
    string countOfAtoms(string &formula) {
        map<string, int> count;
        helper(formula, count);
        string res;
        for (auto it = count.begin(); it != count.end(); it++) {
            res += it->first;
            if (it->second > 1){
                stringstream ss;
                ss << it->second;
                res += ss.str();
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string str("H2O");
    cout << s.countOfAtoms(str);
}

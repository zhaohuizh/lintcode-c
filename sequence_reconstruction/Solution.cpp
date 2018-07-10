#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
class Solution {

public:
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        unordered_map<int, int> degrees;
        unordered_map<int, vector<int>> pres;
        for (vector<int> seq : seqs) {
            for (int num : seq) {
                degrees[num] = 0;
            }
        }
        for (vector<int> seq : seqs) {
            if (seq.empty()) continue;
            for (auto it = seq.begin() + 1; it < seq.end(); ++it) {
                int pre = *(it - 1);
                int aft = *it;
                degrees[aft]++;
                pres[pre].push_back(aft);
            }
        }
        queue<int> queue;
        for (auto it = degrees.begin(); it != degrees.end(); ++it) {
            if (it->second == 0) {
                queue.push(it->first);
            }
        }
        int i = 0;
        while(!queue.empty()) {
            if (queue.size() != 1) {
                return false;
            }
            int cur = queue.front();
            if (cur != org[i++]){
                return false;
            }
            queue.pop();
            for (int dep : pres[cur]) {
                degrees[dep]--;
                if (degrees[dep] == 0) {
                    queue.push(dep);
                }
            }
        }
        return i == org.size();
    }
};

int main() {
    Solution* s = new Solution();
    vector<int> org;
    vector<vector<int> > seqs;
    org.push_back(1);
    org.push_back(2);
    org.push_back(3);
    vector<int> one;
    one.push_back(1);
    one.push_back(2);
    vector<int> two;
    two.push_back(1);
    two.push_back(3);
    vector<int> three;
    three.push_back(2);
    three.push_back(3);
    seqs.push_back(one);
    seqs.push_back(two);
    seqs.push_back(three);

    bool ret = s->sequenceReconstruction(org, seqs);
    cout << ret << endl;
}

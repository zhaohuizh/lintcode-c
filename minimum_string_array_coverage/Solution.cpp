#include <string>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
bool include(vector<string> &tagList, unordered_map<string, int>& map) {
    if (map.size() < tagList.size()) return false;
    for (string tag : tagList) {
        if (map.find(tag) == map.end()) {
            return false;
        }
    }
    return true;
}
public:
    /**
     * @param tagList: The tag list.
     * @param allTags: All the tags.
     * @return: Return the answer
     */
    int getMinimumStringArray(vector<string> &tagList, vector<string> &allTags) {
        int res = INT_MAX;
        unordered_map<string, int> map;
        set<string> set;
        for (string tag : tagList) {
            set.insert(tag);
        }
        int j = 0;
        for (int i = 0; i < allTags.size(); i++) {
            if (map.find(allTags[i]) == map.end()) {
                map[allTags[i]] = 1;
                set.erase(allTags[i]);
            } else {
                map[allTags[i]]++;
            }
            while (j < allTags.size()) {
                if (set.size() == 0) {
                    res = min(res, i - j + 1);
                    if (map[allTags[j]] > 1) {
                        map[allTags[j]]--;
                    } else {
                        map.erase(allTags[j]);
                        set.insert(allTags[j]);
                    }
                    j++;
                } else {
                    break;
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};

int main() {
    string all[] = {"cawb","ocmhj","ocmhj","sl","r","boz","rvi","scn","sl","ocmhj","w","vxeaw","cawb","w","ocmhj","ocmhj","igyef","ocmhj","w","ocmhj","pxd"};
    string tags[] = {"cawb","sl","ocmhj","w"};
    vector<string> allTags(begin(all), end(all));
    vector<string> tagList(begin(tags), end(tags));
    Solution s;
    s.getMinimumStringArray(tagList, allTags);
}

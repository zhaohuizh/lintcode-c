#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    unordered_map<string, vector<string>> map;
    unordered_map<string, int> distance;

    vector<string> getNextWord(string& word, unordered_set<string>& dict) {
        vector<string> res;
        for (int i = 0; i < word.size(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (word[i] == c) {
                    continue;
                }   
                string copy(word);
                copy[i] = c;
                if (dict.find(copy) != dict.end()) {
                    res.push_back(copy);
                }
            }   
        }   
        return res;
    }   

    void dfs(string& start, string& end, vector<vector<string>>& res, vector<string> cur) {
        if (start == end) {
            cur.insert(cur.begin(), start);
            res.push_back(cur);
            return;
        }
        vector<string> pres = map[end];
        for (string pre : pres) {
                cur.insert(cur.begin(), end);
                dfs(start, pre, res, cur);
                cur.erase(cur.begin());
        }
        return;
    }
    
    void bfs(string& start, string& end, unordered_set<string>& dict) {
        bool targetFound = false;
        int level = 1;
        queue<string> queue;
        queue.push(start);
        distance[start] = 0;
        while(!queue.empty()) {
            if (targetFound) break;
            int size = queue.size();
            for (int i = 0; i < size; i++){
                string str = queue.front();
                queue.pop();
                vector<string> nexts = getNextWord(str, dict);
                for (string next : nexts) {
                    if (next == end) {
                        targetFound = true;
                    }
                    if (distance.find(next) == distance.end()) {
                        distance[next] = level;
                        queue.push(next);
                    } else if (distance[next] < level) {
                        continue;
                    }
                    map[next].push_back(str);
                }
            }
            level++;
        }
    }
    
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: a list of lists of string
     */
    vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict) {
        vector<vector<string>> res;
        bfs(start, end, dict);
        vector<string> cur;
        dfs(start, end, res, cur);
        return res;
    }
};

int main() {
    Solution s;
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");
    string start("hit");
    string end("cog");
    s.findLadders(start, end, dict);
}

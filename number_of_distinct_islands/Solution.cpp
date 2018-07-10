#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
private:
    bool valid(vector<vector<int>>& maze, int x, int y) {
        int m = maze.size();
        int n = maze[0].size();
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool helper(vector<vector<int>> &maze, int i, int j, int d_x, int d_y) {
        int direct_x[4] = {0, 0, -1, 1};
        int direct_y[4] = {1, -1, 0, 0};
        
        vector<vector<vector<bool>>> flags;
        for (int i = 0; i < maze.size(); i++) {
            vector<vector<bool>> one;
            for (int j = 0; j < maze[0].size(); j++) {
                vector<bool> two;
                two.push_back(false);
                two.push_back(false);
                two.push_back(false);
                two.push_back(false);
                one.push_back(two);
            }
            flags.push_back(one);
        }
        maze[i][j] = 0;
        
        int direction = 0;
        while (true) {
            int k = direction % 4;
            int x = direct_x[k] + i;
            int y = direct_y[k] + j;
            if(valid(maze, x, y) && maze[x][y] == 0) {
                if (x == d_x && y == d_y) {
                    return true;
                }
                if (flags[x][y][k]) {
                    return false;
                } else {
                    flags[x][y][k] = true;
                    i = x;
                    j = y;
                }
            } else {
                direction++;
            }
        }
        return false;
    }
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        if(maze.empty()|| maze[0].empty()) {
            return false;
        }
        return helper(maze, start[1], start[0], destination[1], destination[0]);
    }
};
int main() {
    Solution* s = new Solution();
    vector<vector<int>> maze;
    vector<int> one;
    one.push_back(0);
    one.push_back(0);
    one.push_back(1);
    one.push_back(0);
    one.push_back(0);
    maze.push_back(one);
    vector<int> two;
    two.push_back(0);
    two.push_back(0);
    two.push_back(0);
    two.push_back(0);
    two.push_back(0);
    maze.push_back(two);
    vector<int> three;
    three.push_back(0);
    three.push_back(0);
    three.push_back(0);
    three.push_back(1);
    three.push_back(0);
    maze.push_back(three);
    vector<int> four;
    four.push_back(1);
    four.push_back(1);
    four.push_back(0);
    four.push_back(1);
    four.push_back(1);
    maze.push_back(four);
    vector<int> five;
    five.push_back(0);
    five.push_back(0);
    five.push_back(0);
    five.push_back(0);
    five.push_back(0);
    maze.push_back(five);


    vector<int> start;
    start.push_back(0);
    start.push_back(4);

    vector<int> end;
    end.push_back(4);
    end.push_back(4);

    bool f = s->hasPath(maze, start, end);
    cout << f;


}

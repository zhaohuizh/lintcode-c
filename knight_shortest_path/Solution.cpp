/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
private:
    bool valid(vector<vector<bool>> &grid, int x, int y) {
        if (x >= 0 && x < grid.size() &&
                y >= 0 && y < grid[0].size() &&
                grid[x][y] == false) {
            return true;
        }
        return false;
    }
public:
    /**
     * @param grid: a chessboard included 0 (false) and 1 (true)
     * @param source: a point
     * @param destination: a point
     * @return: the shortest path 
     */
    int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
        if (grid.size() == 0 || grid[0].size() == 0) return -1;
        int x[8] = {1, 1, -1, -1, 2, 2, -2, -2};
        int y[8] = {2, -2, 2, -2, 1, -1, 1, -1};
        queue<Point> queue;
        if (valid(grid, source.x, source.y)) {
            queue.push(source);
        }
        int ret = 0;
        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                Point curr = queue.front();
                queue.pop();
                if (curr.x == destination.x && curr.y == destination.y) {
                    return ret;
                }
                for (int j = 0; j < 8; j++) {
                    if (valid(grid, curr.x + x[j], curr.y + y[j])) {
                        queue.push(Point(curr.x + x[j], curr.y + y[j]));
                    }
                }
            }
            ret++;
        }
        return -1;
    }
};

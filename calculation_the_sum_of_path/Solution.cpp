#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

bool sortfunc (Point& p1, Point& p2) {
    return (p1.x <= p2.x && p1.y <= p2.y);
};

class Solution {
private:
    long long sumPath(int s_x, int s_y, int e_x, int e_y) {
        int x_diff = abs(e_x - s_x);
        int y_diff = abs(e_y - s_y);
        if (x_diff == 0 || y_diff == 0) {
            return 1;
        }
        
        int total_diff = x_diff + y_diff;
        long long res = 1;
        for (int i = 0; i < x_diff; i++) {
            res *= (total_diff - i);
            res /= (i + 1);
            res %= 1000000007;
        }
        return res;
    }
    
    bool validPoint(int l, int w, Point p) {
        return p.x >= 0 && p.x < l && p.y >= 0 && p.y < w;
    }
    
    bool valid(Point p1, Point p2) {
        return (p1.x >= p2.x && p1.y >= p2.y) || (p1.x <= p2.x && p1.y <= p2.y);
    }
    
    
public:
    /**
     * @param l: The length of the matrix
     * @param w: The width of the matrix
     * @param points: three points 
     * @return: The sum of the paths sum
     */
    long long calculationTheSumOfPath(int l, int w, vector<Point> &points) {
        points.push_back(Point(1, 1));
        points.push_back(Point(l, w));
        sort(points.begin(), points.end(), sortfunc);
        
        long long res = 1;
        for (int i = 1; i < points.size(); i++) {
            res *= sumPath(points[i - 1].x, points[i - 1].y, points[i].x, points[i].y);
            res %= 1000000007;
        }
        return res;
        
        /*
        for (Point p : points) {
            if (!validPoint(l, w, p)) {
                return INT_MIN;
            }
        }
        
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 3; j++) {
                if (!valid(points[i], points[j])) {
                    return INT_MIN;
                }
            }
        }
        */
    }
};

int main(){
    Point p1(45, 48);
    Point p2(15, 29);
    Point p3(92, 100);
    vector<Point> vec;
    vec.push_back(p1);
    vec.push_back(p2);
    vec.push_back(p3);
    Solution s;
    s.calculationTheSumOfPath(92, 100, vec);
}

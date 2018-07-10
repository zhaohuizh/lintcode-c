#include <climits>
#include <stdio.h>

class Solution {
public:
    /**
     * @param n: An integer
     * @return: the nth prime number as description.
     */
    int nthUglyNumber(int n) {
       if (n < 1) return INT_MIN;
        if (n == 1) return 1;
        int count = 1;
        int tmp[3] = {2, 3, 5};
        int diff[3] = {2, 3, 5};
        int tgt = 0;
        int prev = 1;
        while (count < n) {
            int min = 0;
            if (tmp[1] < tmp[min]) {
                min = 1;
            }
            if (tmp[2] < tmp[min]) {
                min = 2;
            }
            tgt = min;
            if (prev != tmp[tgt]) {
               count++; 
            }
            prev = tmp[tgt];
            tmp[tgt] += diff[tgt];
            
        }
        return prev; 
    }
};
int main() {
    Solution s;
    for (int i = 1; i <= 41; i++) {
        int res = s.nthUglyNumber(12);
        printf("%d\n", res);
    }
}

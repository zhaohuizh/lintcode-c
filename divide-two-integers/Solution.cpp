#include <climits>
#include <algorithm>
class Solution {
public:
    /**
     * @param dividend: the dividend
     * @param divisor: the divisor
     * @return: the result
     */
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return INT_MAX;
        }
        bool negative = (dividend < 0) ^ (divisor < 0);
        long long a = dividend >= 0 ? dividend : -(long long) dividend;
        long long b = divisor >= 0 ? divisor : -(long long) divisor;
        long long res = 0;
        while (a >= b) {
            int shift = 0;
            while (a >= (b << shift)) {
                shift++;
            }
            a -= b << (shift - 1);
            res += (1 << (shift - 1));
        }
        res = negative ? - res : res;
        if (res > INT_MAX) {
            return INT_MAX;
        }
        return res;
    }
};

int main() {
    Solution s;
    s.divide(-2147483648, -1);
}

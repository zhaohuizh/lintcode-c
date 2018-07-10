class Solution {
private:
    double power(double x, int n) {
        if (n == 0) return 1;
        if (x == 0 || n == 1) return x;
        double half = power (x, n / 2);
        if (n % 2) {
            return half * half * x;
        } else {
            return half * half;
        }
    }
public:
    /*
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    double myPow(double x, int n) {
        if (n < 0) {
            return power(1.0 / x, 0 - n);
        } else {
            return power(x, n);
        }
    }
};

int main() {
    double x = 2.00000;
    int n = -2147483648;
    Solution s;
    int res = s.myPow(x, n);
}

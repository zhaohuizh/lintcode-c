class Solution {
public:
  /**
   * @param n: an integer
   * @return: a boolean which equals to true if the first player will win
   */
  bool firstWillWin(int n) {
    // write your code here
    bool flag[n];
    flag[0] = true;
    flag[1] = true;
    for(int i = 2; i < n; ++i){
      if(flag[i - 1] && flag[i - 2]){
        flag[i] = false;
      }else{
        flag[i] = true;
      }
    }
    return flag[n - 1];
  }
};

/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 *
 * https://leetcode.cn/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (67.84%)
 * Likes:    2110
 * Dislikes: 0
 * Total Accepted:    649.7K
 * Total Submissions: 957.6K
 * Testcase Example:  '12'
 *
 * 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
 *
 * 完全平方数
 * 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9
 * 和 16 都是完全平方数，而 3 和 11 不是。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 12
 * 输出：3
 * 解释：12 = 4 + 4 + 4
 *
 * 示例 2：
 *
 *
 * 输入：n = 13
 * 输出：2
 * 解释：13 = 4 + 9
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^4
 *
 *
 */
#include <vector>
using namespace std;
// 收获：一维动规的递推式不一定只是简单加减，也可以是循环
//  @lc code=start
class Solution {
public:
  int numSquares(int n) {
    vector<int> ret(n + 1);
    ret[0] = 0;
    for (int i = 1; i <= n; i++) {
      ret[i] = i;
      for (int j = 1; j * j <= i; j++) {
        ret[i] = min(ret[i - j * j] + 1, ret[i]);
      }
    }
    return ret[n];
  }
};
// @lc code=end

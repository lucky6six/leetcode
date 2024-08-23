/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 *
 * https://leetcode.cn/problems/happy-number/description/
 *
 * algorithms
 * Easy (64.05%)
 * Likes:    1547
 * Dislikes: 0
 * Total Accepted:    496.7K
 * Total Submissions: 773.9K
 * Testcase Example:  '19'
 *
 * 编写一个算法来判断一个数 n 是不是快乐数。
 *
 * 「快乐数」 定义为：
 *
 *
 * 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
 * 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
 * 如果这个过程 结果为 1，那么这个数就是快乐数。
 *
 *
 * 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 19
 * 输出：true
 * 解释：
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 2
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 2^31 - 1
 *
 *
 */
//关键点为题目给出若为false则必是无限循环，即出现重复则return
//false,本题重点转化为检测谋职是否出现过（在出现集中）
//若value值只需要1/0就用set，否则使用map
//若key值只需要有限自然数，则用数组，否则使用map
//在hash问题中，可以将数组和set视作特殊的map
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
  int happy(int n) {
    //定义变量记得初始化
    int sum = 0;
    int tmp = 0;
    while (n > 0) {
      tmp = n % 10;
      n = n / 10;
      sum = sum + tmp * tmp;
    }
    return sum;
  }
  bool isHappy(int n) {
    set<int> number = {0};
    while (number.find(n) == number.end()) {
      number.insert(n);
      n = happy(n);
      if (n == 1)
        return true;
    }
    return false;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode.cn/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (39.18%)
 * Likes:    2647
 * Dislikes: 0
 * Total Accepted:    530K
 * Total Submissions: 1.4M
 * Testcase Example:  '"(()"'
 *
 * 给你一个只包含 '(' 和
 * ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "(()"
 * 输出：2
 * 解释：最长有效括号子串是 "()"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = ")()())"
 * 输出：4
 * 解释：最长有效括号子串是 "()()"
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = ""
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= s.length <= 3 * 10^4
 * s[i] 为 '(' 或 ')'
 *
 *
 *
 *
 */
// 一眼动规/栈
#include <string>
#include <vector>
using namespace std;
//  @lc code=start
class Solution {
public:
  int longestValidParentheses(string s) {
    int length = s.size();
    int ret = 0;
    if (length < 2)
      return 0;
    vector<int> dp(length + 2);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 1; i < length; i++) {
      if (s[i] == '(') {
        dp[i + 1] = 0;
        continue;
      }
      if (s[i - 1] == '(')
        dp[i + 1] = dp[i - 1] + 2;
      else if (i - dp[i] - 1 >= 0 && s[i - dp[i] - 1] == '(')
        dp[i + 1] = dp[i - dp[i] - 1] + 2 + dp[i];
      else
        dp[i + 1] = 0;
      ret = max(ret, dp[i + 1]);
    }
    return ret;
  }
};
// @lc code=end

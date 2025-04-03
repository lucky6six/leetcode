/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (39.16%)
 * Likes:    7553
 * Dislikes: 0
 * Total Accepted:    1.9M
 * Total Submissions: 4.9M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的 回文 子串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "cbbd"
 * 输出："bb"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 *
 *
 */
// 二维动规，记录i，j字串是否为回文串
// 动规：初始条件，迭代式子，提取结果
// 较之一般题的难点在于需要特殊的遍历（填表）顺序，即从对角线向两边填。
#include <string>
using namespace std;
//  @lc code=start
class Solution {
public:
  string longestPalindrome(string s) {
    int length = s.size();
    bool dp[length][length];
    int ret = 0;
    int pos = 0;
    // 初始条件，长度为1
    for (int i = 0; i < length; i++) {
      dp[i][i] = true;
    }
    // 初始条件，长度为2
    for (int i = 0; i < length - 1; i++) {
      dp[i][i + 1] = (s[i] == s[i + 1]);
    }
    // 长度递增填表
    for (int i = 2; i < length; i++) {
      for (int j = 0; j < length - i; j++) {
        dp[j][j + i] = (dp[j + 1][j + i - 1] && (s[j] == s[j + i]));
      }
    }
    for (int i = 0; i < length; i++) {
      for (int j = i; j < length; j++) {
        if (dp[i][j] == true && j - i + 1 > ret) {
          ret = j - i + 1;
          pos = i;
        }
      }
    }
    return s.substr(pos, ret);
  }
};
// @lc code=end

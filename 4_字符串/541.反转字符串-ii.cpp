/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 *
 * https://leetcode.cn/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (57.51%)
 * Likes:    589
 * Dislikes: 0
 * Total Accepted:    270.5K
 * Total Submissions: 471K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这
 * 2k 字符中的前 k 个字符。
 *
 *
 * 如果剩余字符少于 k 个，则将剩余字符全部反转。
 * 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "abcdefg", k = 2
 * 输出："bacdfeg"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "abcd", k = 2
 * 输出："bacd"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^4
 * s 仅由小写英文组成
 * 1 <= k <= 10^4
 *
 *
 */
#include <algorithm>
#include <string>

using namespace std;
//在344中自己实现了反转字符串函数，以后直接用库函数reverse了
// @lc code=start
class Solution {
public:
  string reverseStr(string s, int k) {
    //记得初始化，反正不亏
    int index = 0;
    int length = s.size();
    while (index < length) {
      if (index + k < length) {
        reverse(s.begin() + index, s.begin() + index + k);
      } else {
        reverse(s.begin() + index, s.end());
      }
      index += 2 * k;
    }
    return s;
  }
};
// @lc code=end

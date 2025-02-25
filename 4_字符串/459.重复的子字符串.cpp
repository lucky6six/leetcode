/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 *
 * https://leetcode.cn/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (51.35%)
 * Likes:    1155
 * Dislikes: 0
 * Total Accepted:    251.9K
 * Total Submissions: 490.2K
 * Testcase Example:  '"abab"'
 *
 * 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "abab"
 * 输出: true
 * 解释: 可由子串 "ab" 重复两次构成。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "aba"
 * 输出: false
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "abcabcabcabc"
 * 输出: true
 * 解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
 *
 *
 *
 *
 * 提示：
 *
 *
 *
 *
 * 1 <= s.length <= 10^4
 * s 由小写英文字母组成
 *
 *
 */
#include <iostream>
#include <string>

using namespace std;
// 那么既然前面有相同的子串，后面有相同的子串，用 s + s，这样组成的字符串中，
// 后面的子串做前串，前面的子串做后串，中间就一定还能组成一个s
// @lc code=start
class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    string ss = s + s;
    ss.erase(ss.begin());
    //不能擦end，记得最后一个元素是end-1
    ss.erase(ss.end() - 1);
    //熟悉一下字符串的用法。
    if (ss.find(s) == string::npos)
      return false;
    return true;
  }
};
// @lc code=end

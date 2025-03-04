/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (40.71%)
 * Likes:    10627
 * Dislikes: 0
 * Total Accepted:    3.3M
 * Total Submissions: 8.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= s.length <= 5 * 10^4
 * s 由英文字母、数字、符号和空格组成
 *
 *
 */
#include <set>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int slow = 0;
    int fast = 0;
    int size = s.size();
    int max = 0;
    int longth = 0;
    set<char> table;
    while (fast < size) {
      if (table.find(s[fast]) == table.end()) {
        table.insert(s[fast]);
        longth++;
        if (longth > max) {
          max = longth;
        }
        fast++;
      } else {
        table.erase(s[slow]);
        longth--;
        slow++;
      }
    }
    return max;
  }
};
// @lc code=end

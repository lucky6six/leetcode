/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode.cn/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (46.98%)
 * Likes:    3147
 * Dislikes: 0
 * Total Accepted:    719.5K
 * Total Submissions: 1.5M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s
 * 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 *
 *
 *
 * 注意：
 *
 *
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 解释：整个字符串 s 是最小覆盖子串。
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 *
 *
 *
 * 提示：
 *
 *
 * ^m == s.length
 * ^n == t.length
 * 1 <= m, n <= 10^5
 * s 和 t 由英文字母组成
 *
 *
 *
 * 进阶：你能设计一个在 o(m+n) 时间内解决此问题的算法吗？
 */
#include <map>
using namespace std;
// @lc code=start
class Solution {
public:
  map<char, int> str;
  bool checksub() {
    for (auto p : str) {
      if (p.second > 0)
        return false;
    }
    return true;
  }
  string minWindow(string s, string t) {
    int size = t.size();
    for (char i = 0; i < size; i++) {
      str[t[i]]++;
    }
    int slow = 0;
    int fast = 0;
    size = s.size();
    int ret = size + 1;
    int retstart;
    bool flag;
    while (fast <= size) {
      flag = checksub();
      if (flag) {
        if (ret > fast - slow) {
          ret = fast - slow;
          retstart = slow;
        }
        str[s[slow]]++;
        slow++;
      } else {
        str[s[fast]]--;
        fast++;
      }
    }
    if (ret > size)
      return "";
    return s.substr(retstart, ret);
  }
};
// @lc code=end

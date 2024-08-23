/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode.cn/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (43.91%)
 * Likes:    4422
 * Dislikes: 0
 * Total Accepted:    1.8M
 * Total Submissions: 4M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 *
 * 有效字符串需满足：
 *
 *
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 每个右括号都有一个对应的相同类型的左括号。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "()"
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "()[]{}"
 * 输出：true
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "(]"
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^4
 * s 仅由括号 '()[]{}' 组成
 *
 *
 */
#include <stack>
#include <string>

using namespace std;
//一眼栈，注意细节：1.最后栈需要空 2.调top前看看栈空不空
// @lc code=start
class Solution {
public:
  stack<char> st;
  bool isValid(string s) {

    for (auto a : s) {
      switch (a) {
      case '}':
        if (!st.empty() && st.top() == '{') {
          st.pop();
        } else {
          return false;
        }
        break;
      case ']':
        if (!st.empty() && st.top() == '[') {
          st.pop();
        } else {
          return false;
        }
        break;
      case ')':
        if (!st.empty() && st.top() == '(') {
          st.pop();
        } else {
          return false;
        }
        break;
      default:
        st.push(a);
        break;
      }
    }
    if (st.empty())
      return true;
    return false;
  }
};
// @lc code=end

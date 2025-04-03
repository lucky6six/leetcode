/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 *
 * https://leetcode.cn/problems/decode-string/description/
 *
 * algorithms
 * Medium (59.19%)
 * Likes:    1922
 * Dislikes: 0
 * Total Accepted:    408.6K
 * Total Submissions: 690.2K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * 给定一个经过编码的字符串，返回它解码后的字符串。
 *
 * 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k
 * 次。注意 k 保证为正整数。
 *
 * 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
 *
 * 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k
 * ，例如不会出现像 3a 或 2[4] 的输入。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "3[a]2[bc]"
 * 输出："aaabcbc"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "3[a2[c]]"
 * 输出："accaccacc"
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "2[abc]3[cd]ef"
 * 输出："abcabccdcdcdef"
 *
 *
 * 示例 4：
 *
 *
 * 输入：s = "abc3[cd]xyz"
 * 输出："abccdcdcdxyz"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 30
 * s 由小写英文字母、数字和方括号 '[]' 组成
 * s 保证是一个 有效 的输入。
 * s 中所有整数的取值范围为 [1, 300] 
 *
 *
 */
// 能想到栈,但条件很复杂
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
  string decodeString(string s) {
    // 两个栈分别压int res和用pair
    stack<pair<int, string>> sta;
    int num = 0;
    string res = "";
    // 循环检查字符串
    for (int i = 0; i < s.size(); i++) {
      // 遇到数字则存入num
      if (s[i] >= '0' && s[i] <= '9') {
        num *= 10;
        num += (s[i] - '0');    // 进入括号前的数字
      } else if (s[i] == '[') { // 进入括号，将该括号的次数和括号前缀串压栈
        sta.push(make_pair(num, res));
        num = 0;
        res = "";
      } else if (s[i] == ']') {      // 遇到]出栈数字和前缀字符串，组装
        int n = sta.top().first;     // 括号中串的循环次数
        string a = sta.top().second; // 进入括号前的串
        sta.pop();
        for (int i = 0; i < n; i++)
          a = a + res; // 循环n次
        res = a;
      } else {
        res += s[i]; // 当前括号中的串
      }
    }
    return res;
  }
};
// @lc code=end

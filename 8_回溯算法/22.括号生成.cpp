/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode.cn/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (78.53%)
 * Likes:    3787
 * Dislikes: 0
 * Total Accepted:    980.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且
 * 有效的 括号组合。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：["()"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 8
 *
 *
 */
// 一眼回溯，要求过程中右括号数量小于左括号
#include <string>
#include <vector>
using namespace std;
//  @lc code=start
class Solution {
public:
  vector<string> ret;
  string tmp;
  int sizeOfLeft = 0;
  void mygenerate(int n) {
    if (tmp.size() == 2 * n) {
      ret.push_back(tmp);
      return;
    }
    // 回溯子节点只有两个'('或')'
    //  可以添加左括号
    if (sizeOfLeft < n) {
      tmp.push_back('(');
      sizeOfLeft++;
      mygenerate(n);
      sizeOfLeft--;
      tmp.pop_back();
    }
    // 左括号大于右括号数量，可以添加右括号
    if (sizeOfLeft > tmp.size() - sizeOfLeft) {
      {
        tmp.push_back(')');
        mygenerate(n);
        tmp.pop_back();
      }
    }
    return;
  }
  vector<string> generateParenthesis(int n) {
    mygenerate(n);
    return ret;
  }
};
// @lc code=end

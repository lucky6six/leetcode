/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (59.42%)
 * Likes:    2805
 * Dislikes: 0
 * Total Accepted:    866.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按
 * 任意顺序 返回。
 *
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：digits = ""
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 *
 *
 */
#include <string>
#include <vector>

using namespace std;
// @lc code=start
//变长的输入，不定的嵌套循环——回溯递归
class Solution {
public:
  vector<string> res;
  //构造映射集
  vector<string> dict = {"0",   "1",   "abc",  "def", "ghi",
                         "jkl", "mno", "pqrs", "tuv", "wxyz"};
  void dfs(string dights, int index, string path) {
    if (index == dights.size()) {
      res.push_back(path);
      return;
    }
    //输入的是char型的'0'-'9'!!!,所以要-'0'才能得到对应的数字。
    for (char c : dict[dights[index] - '0']) {
      //值传递，利用调用栈回溯。
      dfs(dights, index + 1, path + c);
    }
    return;
  }
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return {};
    }
    string path = "";
    dfs(digits, 0, path);
    return res;
  }
};
// @lc code=end

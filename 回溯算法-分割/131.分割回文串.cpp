/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode.cn/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (73.47%)
 * Likes:    1777
 * Dislikes: 0
 * Total Accepted:    395.7K
 * Total Submissions: 538.5K
 * Testcase Example:  '"aab"'
 *
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s
 * 所有可能的分割方案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "aab"
 * 输出：[["a","a","b"],["aa","b"]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a"
 * 输出：[["a"]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 16
 * s 仅由小写英文字母组成
 *
 *
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> res;
  vector<string> path;
  string str;
  void dfs(int index) {
    if (index == str.size()) {
      res.push_back(path);
      return;
    }
    //每层选取下一个分割点，分了之后后续字符串进入下一层分割
    for (int i = index; i < str.size(); i++) {
      string test = str.substr(index, i - index + 1);
      string rev = test;
      reverse(rev.begin(), rev.end());
      //这里判断回文串时可以用动规的思想提前做好判断表
      // void computePalindrome(const string &s) {
      //   // isPalindrome[i][j] 代表 s[i:j](双边包括)是否是回文字串
      //   isPalindrome.resize(
      //       s.size(),
      //       vector<bool>(s.size(), false)); // 根据字符串s,
      //       刷新布尔矩阵的大小
      //   for (int i = s.size() - 1; i >= 0; i--) {
      //     // 需要倒序计算, 保证在i行时, i+1行已经计算好了
      //     for (int j = i; j < s.size(); j++) {
      //       if (j == i) {
      //         isPalindrome[i][j] = true;
      //       } else if (j - i == 1) {
      //         isPalindrome[i][j] = (s[i] == s[j]);
      //       } else {
      //         isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i + 1][j -
      //         1]);
      //       }
      //     }
      //   }
      // }
      if (test == rev) {
        path.push_back(test);
        dfs(i + 1);
        path.pop_back();
      }
    }
    return;
  }
  vector<vector<string>> partition(string s) {
    str = s;
    dfs(0);
    return res;
  }
};
// @lc code=start
class Solution {
public:
  //结果返回集
  vector<vector<string>> res;
  //当前路径
  vector<string> path;
  //输入字符串做全局变量，减少递归间的传递
  string str;
  void dfs(int index) {
    if (index == str.size()) {
      res.push_back(path);
      return;
    }
    for (int i = index; i < str.size(); i++) {
      string test = str.substr(index, i - index + 1); // start,length
      string rev = test;
      reverse(rev.begin(), rev.end());
      if (test == rev) {
        path.push_back(test);
        dfs(i + 1);
        path.pop_back();
      }
    }
    return;
  }
  vector<vector<string>> partition(string s) {
    str = s;
    dfs(0);
    return res;
    str = 100;
  }
};
// @lc code=end

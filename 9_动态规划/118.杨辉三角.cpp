/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode.cn/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (77.08%)
 * Likes:    1226
 * Dislikes: 0
 * Total Accepted:    617.4K
 * Total Submissions: 800.9K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
 *
 * 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 *
 *
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: numRows = 5
 * 输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 *
 *
 * 示例 2:
 *
 *
 * 输入: numRows = 1
 * 输出: [[1]]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ret;
    vector<int> a;
    a.push_back(1);
    ret.push_back(a);
    for (int i = 1; i < numRows; i++) {
      vector<int> tmp(i + 1);
      tmp[0] = 1;
      for (int j = 1; j < i; j++) {
        tmp[j] = ret[i - 1][j - 1] + ret[i - 1][j];
      }
      tmp[i] = 1;
      ret.push_back(tmp);
    }
    return ret;
  }
};
// @lc code=end

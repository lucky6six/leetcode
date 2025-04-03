/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode.cn/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (71.60%)
 * Likes:    1777
 * Dislikes: 0
 * Total Accepted:    723.7K
 * Total Submissions: 1M
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格 grid
 * ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 *
 * 说明：每次只能向下或者向右移动一步。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
 * 输出：7
 * 解释：因为路径 1→3→1→1→1 的总和最小。
 *
 *
 * 示例 2：
 *
 *
 * 输入：grid = [[1,2,3],[4,5,6]]
 * 输出：12
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 200
 * 0 <= grid[i][j] <= 200
 *
 *
 */
// 一眼动规
#include <vector>
using namespace std;
//  @lc code=start
class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int dp[m][n];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0) {
          dp[i][j] = grid[0][0];
        } else if (i == 0) {
          dp[i][j] = grid[i][j] + dp[i][j - 1];
        } else if (j == 0) {
          dp[i][j] = grid[i][j] + dp[i - 1][j];
        } else {
          dp[i][j] = grid[i][j] + min(dp[i][j - 1], dp[i - 1][j]);
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};
// @lc code=end

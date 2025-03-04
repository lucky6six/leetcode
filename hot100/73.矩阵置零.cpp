/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 *
 * https://leetcode.cn/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (69.57%)
 * Likes:    1167
 * Dislikes: 0
 * Total Accepted:    496.4K
 * Total Submissions: 713.5K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0
 * 。请使用 原地 算法。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * 输出：[[1,0,1],[0,0,0],[1,0,1]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * 输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[0].length
 * 1 <= m, n <= 200
 * -2^31 <= matrix[i][j] <= 2^31 - 1
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
 * 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
 * 你能想出一个仅使用常量空间的解决方案吗？
 *
 *
 */

// 简单粗暴的思路，用常量空间记录首行有无0，用首行/列记录本行/列有无0，然后反向更新。
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    bool col = false;
    bool raw = false;
    int col_size = matrix.size();
    int raw_size = matrix[0].size();
    for (int i = 0; i < col_size; i++) {
      if (matrix[i][0] == 0)
        col = true;
    }
    for (int i = 0; i < raw_size; i++) {
      if (matrix[0][i] == 0)
        raw = true;
    }
    for (int i = 1; i < col_size; i++) {
      for (int j = 1; j < raw_size; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }
    for (int i = 1; i < col_size; i++) {
      for (int j = 1; j < raw_size; j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }
    if (col) {
      for (int i = 0; i < col_size; i++) {
        matrix[i][0] = 0;
      }
    }
    if (raw) {
      for (int i = 0; i < raw_size; i++) {
        matrix[0][i] = 0;
      }
    }
    return;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode.cn/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (52.73%)
 * Likes:    1873
 * Dislikes: 0
 * Total Accepted:    676.3K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序
 * ，返回矩阵中的所有元素。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1
 * -100
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int istart = 0;
    int jstart = 0;
    int iend = matrix.size() - 1;
    int jend = matrix[0].size() - 1;
    vector<int> ret;
    while (istart <= iend && jstart <= jend) {
      for (int j = jstart; j <= jend; j++) {
        ret.push_back(matrix[istart][j]);
      }
      istart++;
      for (int i = istart; i <= iend; i++) {
        ret.push_back(matrix[i][jend]);
      }
      jend--;
      // 检查一下，防止n*(n+1)纬数组出问题
      if (istart > iend || jstart > jend) {
        break;
      }
      for (int j = jend; j >= jstart; j--) {
        ret.push_back(matrix[iend][j]);
      }
      iend--;
      for (int i = iend; i >= istart; i--) {
        ret.push_back(matrix[i][jstart]);
      }
      jstart++;
    }
    return ret;
  }
};
// @lc code=end

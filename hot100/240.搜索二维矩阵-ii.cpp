/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 *
 * https://leetcode.cn/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (55.06%)
 * Likes:    1613
 * Dislikes: 0
 * Total Accepted:    570.3K
 * Total Submissions: 1M
 * Testcase Example:
 '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n'
 + '5'
 *
 * 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target
 。该矩阵具有以下特性：
 *
 *
 * 每行的元素从左到右升序排列。
 * 每列的元素从上到下升序排列。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix =
 * [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
 * target = 5
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix =
 * [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
 * target = 20
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= n, m <= 300
 * -10^9 <= matrix[i][j] <= 10^9
 * 每行的所有元素从左到右升序排列
 * 每列的所有元素从上到下升序排列
 * -10^9 <= target <= 10^9
 *
 *
 */
#include <vector>
using namespace std;
// 从右上角开始，利用行列单调性排除行/列，直至右下角O（m+n）
//  @lc code=start
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size() - 1;
    int n = matrix[0].size() - 1;
    int i = 0;
    int j = n;
    while (i <= m && j >= 0) {
      int cur = matrix[i][j];
      if (cur == target)
        return true;
      if (cur > target)
        j--;
      if (cur < target)
        i++;
    }
    return false;
  }
};
// @lc code=end

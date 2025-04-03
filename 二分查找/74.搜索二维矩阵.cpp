/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 *
 * https://leetcode.cn/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (50.83%)
 * Likes:    1022
 * Dislikes: 0
 * Total Accepted:    514.8K
 * Total Submissions: 1M
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3'
 *
 * 给你一个满足下述两条属性的 m x n 整数矩阵：
 *
 *
 * 每行中的整数从左到右按非严格递增顺序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 *
 *
 * 给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
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
 * 1 <= m, n <= 100
 * -10^4 <= matrix[i][j], target <= 10^4
 *
 *
 */
// 两次二分搜索
#include <vector>
using namespace std;
//  @lc code=start
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int l = 0;
    int r = matrix.size();
    int mid = (l + r) / 2;
    while (l < r) {
      // 二分查找的精髓是明确区间的开闭,我选择左闭右开
      if (matrix[mid][0] == target)
        return true;
      if (matrix[mid][0] > target) {
        r = mid;
      } else {
        l = mid + 1;
      }
      mid = (r + l) / 2;
    }
    int target_raw = mid - 1;
    if (target_raw < 0)
      return false;
    l = 0;
    r = matrix[target_raw].size();
    mid = (l + r) / 2;
    while (l < r) {
      // 二分查找的精髓是明确区间的开闭
      if (matrix[target_raw][mid] == target)
        return true;
      if (matrix[target_raw][mid] > target) {
        r = mid;
      } else {
        l = mid + 1;
      }
      mid = (r + l) / 2;
    }
    return false;
  }
};
// @lc code=end

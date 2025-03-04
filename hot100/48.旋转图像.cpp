/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 *
 * https://leetcode.cn/problems/rotate-image/description/
 *
 * algorithms
 * Medium (77.88%)
 * Likes:    2015
 * Dislikes: 0
 * Total Accepted:    706.7K
 * Total Submissions: 907.5K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
 *
 * 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要
 * 使用另一个矩阵来旋转图像。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[[7,4,1],[8,5,2],[9,6,3]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * 输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 20
 * -1000 <= matrix[i][j] <= 1000
 *
 *
 *
 *
 */
// 注意迭代方式，以圈为单位迭代，以四个为单位更改。
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int end = matrix.size() - 1;
    int start = 0;
    while (start <= end) {
      int length = end - start;
      int tmp;
      for (int i = 0; i < length; i++) {
        tmp = matrix[start][start + i];
        matrix[start][start + i] = matrix[end - i][start];
        matrix[end - i][start] = matrix[end][end - i];
        matrix[end][end - i] = matrix[start + i][end];
        matrix[start + i][end] = tmp;
      }
      start++;
      end--;
    }
    return;
  }
};
// @lc code=end

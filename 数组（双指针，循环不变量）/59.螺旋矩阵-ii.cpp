/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode.cn/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (71.24%)
 * Likes:    1271
 * Dislikes: 0
 * Total Accepted:    409K
 * Total Submissions: 575.1K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n ，生成一个包含 1
 * 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：[[1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 *
 *
 */
//类似题目
// 54.螺旋矩阵
// 剑指Offer 29.顺时针打印矩阵
// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    // 初始化二维vector;
    vector<vector<int>> ret(n, vector<int>(n));
    int i = 0, j = 0;
    int num = 1;
    //注意初始化时的数值与索引差一
    n--;
    //用于记录终止条件
    int q = n;
    //调整画圈范围
    int offset = 0;
    //     而求解本题依然是要坚持循环不变量原则。
    // 模拟顺时针画矩阵的过程:
    // - 填充上行从左到右
    // - 填充右列从上到下
    // - 填充下行从右到左
    // - 填充左列从下到上
    // 由外向内一圈一圈这么画下去。
    // 可以发现这里的边界条件非常多，在一个循环中，如此多的边界条件，如果不按照固定规则来遍历，那就是一进循环深似海。
    // 这里一圈下来，我们要画每四条边，这四条边怎么画，每画一条边都要坚持一致的左闭右开，或者左开右闭的原则，这样这一圈才能按照统一的规则画下来。
    // 可以看出每一个拐角处的处理规则，拐角处让给新的一条边来继续画。
    while (q > 0) {
      while (j < n - offset) {
        ret[i][j] = num;
        j++;
        num++;
      }
      while (i < n - offset) {
        ret[i][j] = num;
        i++;
        num++;
      }
      while (j > 0 + offset) {
        ret[i][j] = num;
        j--;
        num++;
      }
      while (i > 0 + offset) {
        ret[i][j] = num;
        i--;
        num++;
      }
      q = q - 2;
      //每圈结束移动终点，推移offset
      i++;
      j++;
      offset++;
    }
    if (q == 0) {
      ret[i][j] = num;
    }
    return ret;
  }
};
// @lc code=end

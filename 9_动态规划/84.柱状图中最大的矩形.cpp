/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode.cn/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (46.89%)
 * Likes:    2878
 * Dislikes: 0
 * Total Accepted:    493.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为
 * 1 。
 *
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 *
 * 输入：heights = [2,1,5,6,2,3]
 * 输出：10
 * 解释：最大的矩形为图中红色区域，面积为 10
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入： heights = [2,4]
 * 输出： 4
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 0
 *
 *
 */
// 等效求出一根柱子的左/右侧且最近的小于其高度的柱子。题解单调栈。
// 遍历时找到一个较小的，那么之前找到的比他大的都可以忽略！（这也就是单调栈的本质）
// 单调栈适用于，只要出现一个增加的，前面的都可以不予考虑
#include <stack>
#include <vector>
using namespace std;
//  @lc code=start
class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    stack<int> sleft, sright; // 单调增栈,只记录索引
    int size = heights.size();
    vector<int> left(size);
    vector<int> right(size);
    if (size == 0)
      return 0;
    // 左右两方向用单调栈，获取距离最近的低于height[i]的位置
    for (int i = 0; i < size; i++) {
      while (!sleft.empty() && heights[sleft.top()] >= heights[i]) {
        sleft.pop();
      }
      if (sleft.empty())
        left[i] = -1;
      else
        left[i] = sleft.top();
      sleft.push(i);
    }
    for (int i = size - 1; i >= 0; i--) {
      while (!sright.empty() && heights[sright.top()] >= heights[i]) {
        sright.pop();
      }
      if (sright.empty())
        right[i] = size;
      else
        right[i] = sright.top();
      sright.push(i);
    }
    int ret = 0;
    for (int i = 0; i < size; i++) {
      ret = max(ret, heights[i] * (right[i] - left[i] - 1));
    }
    return ret;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode.cn/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (64.74%)
 * Likes:    5547
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 1.9M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1
 * 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1]
 * 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
 *
 *
 * 示例 2：
 *
 *
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 *
 *
 */
#include <vector>
using namespace std;
// 双指针法，最后一定在最高点重合
// 动态规划，分别接左右，最后取重合面积
// 单调栈
//  @lc code=start
class Solution {
public:
  int trap(vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;
    int ret = 0;
    int h = 0;
    while (left < right) {
      int tmp = min(height[left], height[right]);
      h = max(h, tmp);
      if (height[left] < height[right]) {
        ret += h - height[left];
        left++;
      } else {
        ret += h - height[right];
        right--;
      }
    }
    return ret;
  }
};
// @lc code=end

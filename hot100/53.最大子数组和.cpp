/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 *
 * https://leetcode.cn/problems/maximum-subarray/description/
 *
 * algorithms
 * Medium (55.92%)
 * Likes:    6928
 * Dislikes: 0
 * Total Accepted:    2M
 * Total Submissions: 3.6M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给你一个整数数组 nums
 * ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 *
 * 子数组 是数组中的一个连续部分。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1]
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [5,4,-1,7,8]
 * 输出：23
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 *
 * 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
 *
 */
// 注意这里元素可能有负数，常规的滑动窗口可能无法解决问题
// 动态规划秒了，记录以i为结尾的最大连续子数组和，只需要考虑前一格是正数还是负数，甚至可以原地做
// 题解中提到一种分治方法。
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int ret = INT_MIN;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      if (i == 0) {
        ret = nums[i];
        continue;
      }
      if (nums[i - 1] > 0)
        nums[i] += nums[i - 1];
      if (nums[i] > ret)
        ret = nums[i];
    }
    return ret;
  }
};
// @lc code=end

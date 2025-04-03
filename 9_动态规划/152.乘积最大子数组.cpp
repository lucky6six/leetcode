/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 *
 * https://leetcode.cn/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (42.48%)
 * Likes:    2379
 * Dislikes: 0
 * Total Accepted:    518.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续
 * 子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
 *
 * 测试用例的答案是一个 32-位 整数。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * -10 <= nums[i] <= 10
 * nums 的任何子数组的乘积都 保证 是一个 32-位 整数
 *
 *
 */
// 看起来还是动态规划，分类讨论
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int length = nums.size();
    vector<int> minarr(length);
    vector<int> maxarr(length);
    int ret = INT_MIN;
    for (int i = 0; i < length; i++) {
      if (i == 0) {
        minarr[0] = nums[0];
        maxarr[0] = nums[0];
        ret = max(maxarr[i], ret);
        continue;
      }
      if (nums[i] > 0) {
        maxarr[i] = max(nums[i], nums[i] * maxarr[i - 1]);
        minarr[i] = min(nums[i], nums[i] * minarr[i - 1]);
      }
      if (nums[i] <= 0) {
        maxarr[i] = max(nums[i], nums[i] * minarr[i - 1]);
        minarr[i] = min(nums[i], nums[i] * maxarr[i - 1]);
      }
      ret = max(maxarr[i], ret);
    }
    return ret;
  }
};
// @lc code=end

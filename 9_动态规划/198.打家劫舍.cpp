/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 *
 * https://leetcode.cn/problems/house-robber/description/
 *
 * algorithms
 * Medium (55.61%)
 * Likes:    3184
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,2,3,1]'
 *
 *
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 *
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下
 * ，一夜之内能够偷窃到的最高金额。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：[1,2,3,1]
 * 输出：4
 * 解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 *
 * 示例 2：
 *
 *
 * 输入：[2,7,9,3,1]
 * 输出：12
 * 解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋
 * (金额 = 1)。 偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 *
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
// 一眼动态规划,初始条件要定好，动态变化要写对，结果明确。
#include <vector>
using namespace std;
// @lc code=start
// class Solution {
// public:
//   int rob(vector<int> &nums) {
//     int size = nums.size();
//     vector<int> result(size);
//     for (int i = 0; i < size; i++) {
//       if (i == 0) {
//         result[0] = nums[0];
//       } else if (i == 1) {
//         result[1] = max(nums[0], nums[1]);
//       } else {
//         result[i] = max(result[i - 2] + nums[i], result[i - 1]);
//       }
//     }
//     return result[size - 1];
//   }
// };
class Solution {
public:
  int rob(vector<int> &nums) {
    int size = nums.size();
    for (int i = 1; i < size; i++) {
      if (i == 1) {
        nums[1] = max(nums[0], nums[1]);
      } else {
        nums[i] = max(nums[i - 2] + nums[i], nums[i - 1]);
      }
    }
    return nums[size - 1];
  }
};
// @lc code=end

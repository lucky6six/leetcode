/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode.cn/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (53.15%)
 * Likes:    2251
 * Dislikes: 0
 * Total Accepted:    686K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给你一个 只包含正整数 的 非空 数组 nums
 * 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 *
 *
 */
// 这是一个np问题，别想关于sizeof（nums）的时间复杂度了，另辟蹊径，以target为目标的背包问题。
// /创建二维数组 dp，包含 n 行 target+1 列，其中 dp[i][j] 表示从数组的 [0,i]
// 下标范围内选取若干个正整数（可以是 0
// 个），是否存在一种选取方案使得被选取的正整数的和等于 j。
// 上述代码的空间复杂度是 O(n×target)。但是可以发现在计算 dp 的过程中，每一行的
// dp 值都只与上一行的 dp
// 值有关，因此只需要一个一维数组即可将空间复杂度降到(每次新增一个num，计算所有target是否能满足)
// O(target)。此时的转移方程为：

#include <vector>
using namespace std;
//  @lc code=start
class Solution {
public:
  bool canPartition(vector<int> &nums) {

    int target = 0;
    for (auto num : nums) {
      target += num;
    }
    if (target % 2)
      return false;
    target /= 2;
    vector<int> dp(target + 1);
    dp[0] = true;
    for (int i = 1; i < target + 1; i++) {
      dp[i] = false;
    }
    for (int i = 0; i < nums.size(); i++) {
      int val = nums[i];
      for (int j = target; j > 0; j--) {
        if (j - val >= 0) {
          dp[j] = dp[j - val] | dp[j];
        }
      }
    }
    return dp[target];
  }
};
// @lc code=end

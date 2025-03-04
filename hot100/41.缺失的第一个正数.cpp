/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode.cn/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (46.40%)
 * Likes:    2292
 * Dislikes: 0
 * Total Accepted:    496K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,0]'
 *
 * 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
 * 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,0]
 * 输出：3
 * 解释：范围 [1,2] 中的数字都在数组中。
 *
 * 示例 2：
 *
 *
 * 输入：nums = [3,4,-1,1]
 * 输出：2
 * 解释：1 在数组中，但 2 没有。
 *
 * 示例 3：
 *
 *
 * 输入：nums = [7,8,9,11,12]
 * 输出：1
 * 解释：最小的正数 1 没有出现。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 */
// 常数额外空间——真常数空间/利用原地数组
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    // 数组本身按索引访问为O（1）的哈希表。(由下标映射到值)
    int size = nums.size();
    int tmp;
    for (int i = 0; i < size; i++) {
      if (nums[i] != i + 1) {
        if (nums[i] > 0 && nums[i] < size && nums[nums[i] - 1] != nums[i]) {
          tmp = nums[nums[i] - 1];
          nums[nums[i] - 1] = nums[i];
          nums[i] = tmp;
          i--;
        }
      }
    }
    for (int i = 0; i < size; i++) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    return size + 1;
  }
};
// @lc code=end

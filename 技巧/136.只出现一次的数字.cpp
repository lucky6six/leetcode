/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 *
 * https://leetcode.cn/problems/single-number/description/
 *
 * algorithms
 * Easy (74.85%)
 * Likes:    3271
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 1.6M
 * Testcase Example:  '[2,2,1]'
 *
 * 给你一个 非空 整数数组 nums
 * ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 *
 * 你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。
 *
 *
 *
 *
 *
 * 示例 1 ：
 *
 *
 * 输入：nums = [2,2,1]
 *
 * 输出：1
 *
 *
 * 示例 2 ：
 *
 *
 * 输入：nums = [4,1,2,1,2]
 *
 * 输出：4
 *
 *
 * 示例 3 ：
 *
 *
 * 输入：nums = [1]
 *
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * -3 * 10^4 <= nums[i] <= 3 * 10^4
 * 除了某个元素只出现一次以外，其余每个元素均出现两次。
 *
 *
 *
 *
 */
// 思考异或^操作，相同的会小乘0
#include <vector>
using namespace std;
//  @lc code=start
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int ret = 0;
    for (auto i : nums) {
      ret = ret ^ i;
    }
    return ret;
  }
};
// @lc code=end

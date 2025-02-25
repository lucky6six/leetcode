/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode.cn/problems/3sum/description/
 *
 * algorithms
 * Medium (37.77%)
 * Likes:    6750
 * Dislikes: 0
 * Total Accepted:    1.7M
 * Total Submissions: 4.5M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i
 * != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
 *
 * 你返回所有和为 0 且不重复的三元组。
 *
 * 注意：答案中不可以包含重复的三元组。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 解释：
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
 * 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
 * 注意，输出的顺序和三元组的顺序并不重要。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,1,1]
 * 输出：[]
 * 解释：唯一可能的三元组和不为 0 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [0,0,0]
 * 输出：[[0,0,0]]
 * 解释：唯一可能的三元组和为 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 *
 *
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
//先排序，递推迭代i，对i右侧作双指针法
//关键要考虑去重
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ret;
    std::sort(nums.begin(), nums.end());
    int length = nums.size();
    int target;
    int left, right;
    for (int i = 0; i < length; i++) {
      target = 0 - nums[i];
      left = i + 1;
      right = length - 1;
      while (left < right) {
        if (nums[left] + nums[right] == target) {
          vector<int> to_insert = {nums[i], nums[left], nums[right]};
          ret.push_back(to_insert);
          //去重防溢出
          while (left < length - 1 && nums[left] == nums[left + 1]) {
            left++;
          }
          left++;
        } else if (nums[left] + nums[right] < target)
          left++;
        else
          right--;
      }
      //去重防溢出
      //说到去重，其实主要考虑三个数的去重。 a, b ,c, 对应的就是
      // nums[i]，nums[left]，nums[right]
      // a如果重复了怎么办，a是nums里遍历的元素，那么应该直接跳过去。
      while (i < length - 1 && nums[i] == nums[i + 1]) {
        i++;
      }
    }
    return ret;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 *
 * https://leetcode.cn/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (44.65%)
 * Likes:    2641
 * Dislikes: 0
 * Total Accepted:    636.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,1,1]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你统计并返回
 * 该数组中和为 k 的子数组的个数 。
 *
 * 子数组是数组中元素的连续非空序列。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,1,1], k = 2
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,3], k = 3
 * 输出：2
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 *
 *
 */
// 先动规得到前缀和，转化为差值为k，然后变为hash解决,注意边界条件，注意需要需要计数，并不是每次遍历只有一个解。
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int size = nums.size();
    unordered_map<int, int> map;
    int count = 0;
    map[0]++;
    for (int i = 0; i < size; i++) {
      if (i > 0)
        nums[i] += nums[i - 1];
      //   map[nums[i]]++;

      if (map.find(nums[i] - k) != map.end()) {
        count += map[nums[i] - k];
      }
      map[nums[i]]++;
    }
    return count;
  }
};
// @lc code=end

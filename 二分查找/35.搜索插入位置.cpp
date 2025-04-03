/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 *
 * https://leetcode.cn/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (47.71%)
 * Likes:    2454
 * Dislikes: 0
 * Total Accepted:    1.7M
 * Total Submissions: 3.5M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 *
 * 请必须使用时间复杂度为 O(log n) 的算法。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [1,3,5,6], target = 5
 * 输出: 2
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [1,3,5,6], target = 2
 * 输出: 1
 *
 *
 * 示例 3:
 *
 *
 * 输入: nums = [1,3,5,6], target = 7
 * 输出: 4
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums 为 无重复元素 的 升序 排列数组
 * -10^4 <= target <= 10^4
 *
 *
 */
// 二分查找的开始！
#include <vector>
using namespace std;
//  @lc code=start
class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size();
    int mid = (l + r) / 2; // 除以二会偏向左边，所以最后的return mid不用-1；
    while (l < r) {
      // 二分查找的精髓是明确区间的开闭
      if (nums[mid] == target)
        return mid;
      if (nums[mid] > target) {
        r = mid;
      } else {
        l = mid + 1;
      }
      mid = (r + l) / 2;
    }
    return mid;
  }
};
// @lc code=end

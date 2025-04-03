/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (44.79%)
 * Likes:    2924
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.6M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值
 * target。请你找出给定目标值在数组中的开始位置和结束位置。
 *
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 *
 * 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 *
 * 示例 2：
 *
 *
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 *
 * 示例 3：
 *
 *
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums 是一个非递减数组
 * -10^9 <= target <= 10^9
 *
 *
 */
// 二分查找，找到后向两侧拓展，但如果依次拓展可能复杂度超过O（logn）
// 两次二分查找，找到最前/最后点
// 直接找target-0.5和target+0.5,绕过复杂的条件判定！
#include <iostream>
#include <vector>
using namespace std;

//  @lc code=start
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    // 需要一个double类型的变量才能存储小数
    double tmp;
    tmp = target - 0.5;
    int l = 0;
    int r = nums.size();
    int mid = (l + r) / 2;
    while (l < r) {
      if (nums[mid] > tmp)
        r = mid;
      else
        l = mid + 1;
      mid = (l + r) / 2;
    }
    int left = mid;

    tmp = target + 0.5;
    l = 0;
    r = nums.size();
    mid = (l + r) / 2;
    while (l < r) {
      if (nums[mid] > tmp)
        r = mid;
      else
        l = mid + 1;
      mid = (l + r) / 2;
    }
    // 没找到的情况
    if (left >= nums.size() || nums[left] != target) {
      return {-1, -1};
    }
    vector<int> ret;

    ret.push_back(left);
    ret.push_back(mid - 1);
    return ret;
  }
};
// @lc code=end
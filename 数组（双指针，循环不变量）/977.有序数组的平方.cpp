/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 *
 * https://leetcode.cn/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (67.89%)
 * Likes:    976
 * Dislikes: 0
 * Total Accepted:    655.6K
 * Total Submissions: 965.4K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方
 * 组成的新数组，要求也按 非递减顺序 排序。
 *
 * 进阶：
 *
 *
 * 请你设计时间复杂度为 O(n) 的算法解决本问题
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
  // my idea,双指针法，一正一副。
  vector<int> sortedSquares(vector<int> &nums) {
    int length = nums.size() - 1;
    int low = 0, high = length;
    vector<int> ret(length + 1);
    //特殊情况，nums大小为1，防止访问到nums[-1]造成错误，平时写代码时不要怕检验麻烦。
    while (high >= 0 && nums[high] > 0) {
      if (nums[high] >= -nums[low]) {
        ret[length] = nums[high] * nums[high];
        high--;
      } else {
        ret[length] = nums[low] * nums[low];
        low++;
      }
      length--;
    }
    while (length >= 0) {
      ret[length] = nums[low] * nums[low];
      low++;
      length--;
    }
    return ret;
  }
};
// @lc code=end

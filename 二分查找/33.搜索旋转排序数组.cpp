/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode.cn/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (44.90%)
 * Likes:    3130
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 2.3M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 整数数组 nums 按升序排列，数组中的值 互不相同 。
 *
 * 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了
 * 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ...,
 * nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3
 * 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
 *
 * 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target
 * ，则返回它的下标，否则返回 -1 。
 *
 * 你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [4,5,6,7,0,1,2], target = 0
 * 输出：4
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [4,5,6,7,0,1,2], target = 3
 * 输出：-1
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1], target = 0
 * 输出：-1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 5000
 * -10^4 <= nums[i] <= 10^4
 * nums 中的每个值都 独一无二
 * 题目数据保证 nums 在预先未知的某个下标上进行了旋转
 * -10^4 <= target <= 10^4
 *
 *
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int l = 1;
    int n = nums.size();
    int r = n - 1;
    int mid;
    int tar = 0;
    while (l <= r) {
      mid = (l + r) / 2;
      if (nums[mid] <= nums[0]) {
        r = mid - 1;
        tar = mid;
      } else {
        l = mid + 1;
      }
    }
    // 找到轴点target，剩下的传统二分
    l = 0;
    r = n;
    while (l < r) {
      mid = (l + r) / 2;
      if (nums[(mid + tar) % n] == target)
        return (mid + tar) % n;
      if (nums[(mid + tar) % n] > target) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return -1;
  }
};
// @lc code=end

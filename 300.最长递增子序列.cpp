/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 *
 * https://leetcode.cn/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (56.93%)
 * Likes:    3886
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2M
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 *
 * 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7]
 * 是数组 [0,3,1,6,2,2,7] 的子序列。
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [10,9,2,5,3,7,101,18]
 * 输出：4
 * 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,1,0,3,2,3]
 * 输出：4
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [7,7,7,7,7,7,7]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 你能将算法的时间复杂度降低到 O(n log(n)) 吗?
 *
 *
 */
// o(n^2)易得，O（nlogn）需要二分查找，这是一种遍历方法。
// 可以考虑贪心法直接记录可能递增子序列，当需要更新时用二分法查找。
// 做法是：维护一个辅助数组 p，它的每一项 p[i] 的含义是，所有长度为
// i+1的上升子序列的末尾元素中的最小值。

#include <vector>
using namespace std;
//  @lc code=start
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int length = nums.size();
    if (length == 0)
      return 0;
    int ret = 1;
    vector<int> lis(length + 1);
    lis[ret] = nums[0];
    for (int i = 1; i < length; i++) {
      if (nums[i] > lis[ret]) {
        ret++;
        lis[ret] = nums[i];
      } else {
        // 替换序列中对应位置的值,这里需要二分法,这里需要确定找到恰小于nums【i】的值，注意边界条件的判断
        int l = 1;
        int r = ret;
        int mid;
        int pos = 0;
        while (l <= r) {
          mid = (l + r) / 2;
          if (lis[mid] < nums[i]) {
            pos = mid;
            l = mid + 1;
          }

          else
            r = mid - 1;
        }
        lis[pos + 1] = nums[i];
      }
    }
    return ret;
  }
};
// @lc code=end

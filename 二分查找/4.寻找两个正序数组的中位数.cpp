/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (43.13%)
 * Likes:    7468
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 2.9M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1
 * 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 *
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
// 转化为找第k小的数，然后二分查找排除
class Solution {
public:
  double getK(vector<int> &nums1, vector<int> &nums2, int k) {
    int left1 = 0;
    int left2 = 0;
    int size1 = nums1.size();
    int size2 = nums2.size();
    while (true) {
      if (left1 == size1) {
        return nums2[left2 + k - 1];
      }
      if (left2 == size2) {
        return nums1[left1 + k - 1];
      }
      if (k == 1) {
        return min(nums1[left1], nums2[left2]);
      }
      int half = k / 2;
      int newLeft1 = min(left1 + half, size1) - 1;
      int newLeft2 = min(left2 + half, size2) - 1;
      if (nums1[newLeft1] <= nums2[newLeft2]) {
        k -= newLeft1 - left1 + 1;
        left1 = newLeft1 + 1;
      } else {
        k -= newLeft2 - left2 + 1;
        left2 = newLeft2 + 1;
      }
    }
    return 0;
  }
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int left1 = 0;
    int left2 = 0;
    int size1 = nums1.size();
    int size2 = nums2.size();
    int k = (size1 + size2) / 2;
    if ((size1 + size2) % 2 == 0) {
      return (getK(nums1, nums2, k) + getK(nums1, nums2, k + 1)) / 2;
    } else {
      return getK(nums1, nums2, k + 1);
    }
  }
};
// @lc code=end

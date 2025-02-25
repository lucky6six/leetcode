/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 *
 * https://leetcode.cn/problems/4sum-ii/description/
 *
 * algorithms
 * Medium (64.38%)
 * Likes:    989
 * Dislikes: 0
 * Total Accepted:    264.9K
 * Total Submissions: 411.3K
 * Testcase Example:  '[1,2]\n[-2,-1]\n[-1,2]\n[0,2]'
 *
 * 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n
 * ，请你计算有多少个元组 (i, j, k, l) 能满足：
 *
 *
 * 0 <= i, j, k, l < n
 * nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
 * 输出：2
 * 解释：
 * 两个元组如下：
 * 1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) +
 * (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) +
 * (-1) + 0 = 0
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == nums1.length
 * n == nums2.length
 * n == nums3.length
 * n == nums4.length
 * 1 <= n <= 200
 * -2^28 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2^28
 *
 *
 */
#include <map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  //乍一看需要四重循环，细细想可以两两一组，做多次二重循环，因为只需统计不同和出现的次数
  //需要上map了
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                   vector<int> &nums4) {
    map<int, int> table;
    int length1 = nums1.size();
    int length2 = nums2.size();
    for (int i = 0; i < length1; i++) {
      for (int j = 0; j < length2; j++) {
        table[nums1[i] + nums2[j]]++;
      }
    }
    int ret = 0;
    //熟悉用冒号进行容器迭代，与上面对比，更加简洁易懂
    for (int c : nums3) {
      for (int d : nums4) {
        if (table.find(0 - c - d) != table.end()) {
          ret += table[0 - c - d];
        }
      }
    }
    return ret;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (60.93%)
 * Likes:    2645
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.1M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 *
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 *
 * 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: [3,2,1,5,6,4], k = 2
 * 输出: 5
 *
 *
 * 示例 2:
 *
 *
 * 输入: [3,2,3,1,2,4,5,5,6], k = 4
 * 输出: 4
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {

public:
  void maxHeapify(vector<int> &nums, int i, int size) {
    int max = i;
    if (2 * i + 1 < size && nums[max] < nums[2 * i + 1]) {
      max = 2 * i + 1;
    }
    if (2 * i + 2 < size && nums[max] < nums[2 * i + 2]) {
      max = 2 * i + 2;
    }
    if (max != i) {
      std::swap(nums[i], nums[max]);
      maxHeapify(nums, max, size);
    }
  }
  void buildMaxHeap(vector<int> &nums, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
      maxHeapify(nums, i, size);
    }
    return;
  }
  int findKthLargest(vector<int> &nums, int k) {
    int size = nums.size();
    // 可以直接用nums原地构造最大堆
    buildMaxHeap(nums, size);
    while (k > 1) {
      std::swap(nums[0], nums[size - 1]);
      size--;
      maxHeapify(nums, 0, size);
      k--;
    }

    return nums[0];
  }
};
// @lc code=end

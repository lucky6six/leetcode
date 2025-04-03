/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 *
 * https://leetcode.cn/problems/rotate-array/description/
 *
 * algorithms
 * Medium (46.20%)
 * Likes:    2325
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2.4M
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * 给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [1,2,3,4,5,6,7], k = 3
 * 输出: [5,6,7,1,2,3,4]
 * 解释:
 * 向右轮转 1 步: [7,1,2,3,4,5,6]
 * 向右轮转 2 步: [6,7,1,2,3,4,5]
 * 向右轮转 3 步: [5,6,7,1,2,3,4]
 *
 *
 * 示例 2:
 *
 *
 * 输入：nums = [-1,-100,3,99], k = 2
 * 输出：[3,99,-1,-100]
 * 解释:
 * 向右轮转 1 步: [99,-1,-100,3]
 * 向右轮转 2 步: [3,99,-1,-100]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 * 0 <= k <= 10^5
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 尽可能想出更多的解决方案，至少有 三种 不同的方法可以解决这个问题。
 * 你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
 *
 *
 */
// 易得但难写tmp轮转需要注意到终止条件(count公约数)，技巧是三个reverse
#include <numeric>
#include <vector>
using namespace std;
//  @lc code=start
class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int size = nums.size();
    k = k % size;
    int count = gcd(size, k);
    int tmp, prev;
    for (int i = 0; i < count; i++) {
      int cur = i;
      prev = nums[cur];
      tmp = nums[cur];
      do {
        tmp = nums[(cur + k) % size];
        nums[(cur + k) % size] = prev;
        prev = tmp;
        cur = (cur + k) % size;
      } while (cur != i);
    }
    return;
  }
};
// class Solution {
// public:
//   void reverse(vector<int> &nums, int start, int end) {
//     while (start < end) {
//       int tmp = nums[start];
//       nums[start] = nums[end];
//       nums[end] = tmp;
//       start++;
//       end--;
//     }
//     return;
//   }
//   void rotate(vector<int> &nums, int k) {
//     int size = nums.size();
//     k = k % size;
//     reverse(nums, 0, size - 1);
//     reverse(nums, 0, k - 1);
//     reverse(nums, k, size - 1);
//     return;
//   }
// };
// @lc code=end

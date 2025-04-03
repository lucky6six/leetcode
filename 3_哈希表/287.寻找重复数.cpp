/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 *
 * https://leetcode.cn/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (65.63%)
 * Likes:    2565
 * Dislikes: 0
 * Total Accepted:    465.5K
 * Total Submissions: 709.3K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * 给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和
 * n），可知至少存在一个重复的整数。
 *
 * 假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。
 *
 * 你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,3,4,2,2]
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [3,1,3,4,2]
 * 输出：3
 *
 *
 * 示例 3 :
 *
 *
 * 输入：nums = [3,3,3,3,3]
 * 输出：3
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^5
 * nums.length == n + 1
 * 1 <= nums[i] <= n
 * nums 中 只有一个整数 出现 两次或多次 ，其余整数均只出现 一次
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 如何证明 nums 中至少存在一个重复的数字?
 * 你可以设计一个线性级时间复杂度 O(n) 的解决方案吗？
 *
 *
 */
// 一眼需要hash，但没有额外空间，想到数组本身作hash表，对于本题，类似布谷hash想法
// 突然注意到不能修改数组nums，想到可以将nums是做有环链表，寻找入环点，快慢指针！
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    int size = nums.size();
    int fast = 0;
    int slow = 0;
    do {
      fast = nums[nums[fast]];
      slow = nums[slow];
    } while (fast != slow);
    slow = 0;
    while (fast != slow) {
      fast = nums[fast];
      slow = nums[slow];
    }
    return slow;
  }
};
// class Solution {
// public:
//   int findDuplicate(vector<int> &nums) {
//     int size = nums.size();
//     int i = 0;
//     while (true) {
//       if (nums[i] == nums[nums[i]])
//         return nums[i];
//       swap(nums[i], nums[nums[i]]);
//     }
//     return -1;
//   }
// };
// @lc code=end

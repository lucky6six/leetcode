/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 *
 * https://leetcode.cn/problems/sort-colors/description/
 *
 * algorithms
 * Medium (62.19%)
 * Likes:    1887
 * Dislikes: 0
 * Total Accepted:    736.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * 给定一个包含红色、白色和蓝色、共 n
 * 个元素的数组 nums ，原地 对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 *
 * 我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 *
 *
 *
 *
 * 必须在不使用库内置的 sort 函数的情况下解决这个问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [2,0,2,1,1,0]
 * 输出：[0,0,1,1,2,2]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [2,0,1]
 * 输出：[0,1,2]
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == nums.length
 * 1 <= n <= 300
 * nums[i] 为 0、1 或 2
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 你能想出一个仅使用常数空间的一趟扫描算法吗？
 *
 *
 */
// 统计数量，及其简单，题目希望用指针交换的方式实现
#include <vector>
using namespace std;
// @lc code=start

class Solution {
public:
  void sortColors(vector<int> &nums) {
    int pos0 = 0;
    int size = nums.size() - 1;
    int pos2 = size;
    for (int i = 0; i <= size; i++) {
      if (i > pos2)
        return;
      if (nums[i] == 0) {
        nums[i] = nums[pos0];
        nums[pos0] = 0;
        pos0++;
      } else if (nums[i] == 2) {
        nums[i] = nums[pos2];
        nums[pos2] = 2;
        pos2--;
        i--;
      }
    }
    return;
  }
};
// class Solution {
// public:
//   void sortColors(vector<int> &nums) {
//     int count0 = 0;
//     int count1 = 0;
//     for (auto num : nums) {
//       if (num == 0)
//         count0++;
//       if (num == 1)
//         count1++;
//     }
//     for (int i = 0; i < nums.size(); i++) {
//       if (count0 > 0) {
//         nums[i] = 0;
//         count0--;
//       } else if (count1 > 0) {
//         nums[i] = 1;
//         count1--;
//       } else {
//         nums[i] = 2;
//       }
//     }
//     return;
//   }
// };
// @lc code=end

/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode.cn/problems/next-permutation/description/
 *
 * algorithms
 * Medium (40.48%)
 * Likes:    2646
 * Dislikes: 0
 * Total Accepted:    599.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,3]'
 *
 * 整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。
 *
 *
 * 例如，arr = [1,2,3] ，以下这些都可以视作 arr
 * 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
 *
 *
 * 整数数组的 下一个排列
 * 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的
 * 下一个排列
 * 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。
 *
 *
 * 例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
 * 类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
 * 而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1]
 * 不存在一个字典序更大的排列。
 *
 *
 * 给你一个整数数组 nums ，找出 nums 的下一个排列。
 *
 * 必须 原地 修改，只允许使用额外常数空间。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：[1,3,2]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [3,2,1]
 * 输出：[1,2,3]
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1,1,5]
 * 输出：[1,5,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 100
 *
 *
 */
#include <vector>
using namespace std;
// 有点背诵的意思了
// 规约：找到i<j,i尽可能靠右，nums[i]<nums[j];交换i，j的值，然后重排nums[i]后面的数，这些数显然降序,反转即可
// 仔细思考，找i，实际上就是找到已经完成全排列的后缀
//  @lc code=start
class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int size = nums.size();
    int i, j, tmp;
    bool flag = true;
    for (i = size - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        // 能找到
        flag = false;
        break;
      }
    }
    // 能找到就交换
    if (!flag) {
      for (j = size - 1; j >= i; j--) {
        if (nums[j] > nums[i])
          break;
      }
      tmp = nums[i];
      nums[i] = nums[j];
      nums[j] = tmp;
    }
    // 反转剩余序列
    for (int index = 1; i + index < size - index; index++) {
      tmp = nums[i + index];
      nums[i + index] = nums[size - index];
      nums[size - index] = tmp;
    }
    return;
  }
};
// @lc code=end

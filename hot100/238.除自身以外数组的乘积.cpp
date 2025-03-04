/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 *
 * https://leetcode.cn/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (77.11%)
 * Likes:    1964
 * Dislikes: 0
 * Total Accepted:    617.9K
 * Total Submissions: 801.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个整数数组 nums，返回
 * 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
 *
 * 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位
 * 整数范围内。
 *
 * 请 不要使用除法，且在 O(n) 时间复杂度内完成此题。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [1,2,3,4]
 * 输出: [24,12,8,6]
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [-1,1,0,-3,3]
 * 输出: [0,0,9,0,0]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= nums.length <= 10^5
 * -30 <= nums[i] <= 30
 * 输入 保证 数组 answer[i] 在  32 位 整数范围内
 *
 *
 *
 *
 * 进阶：你可以在 O(1) 的额外空间复杂度内完成这个题目吗？（
 * 出于对空间复杂度分析的目的，输出数组 不被视为 额外空间。）
 *
 */
// 两眼动规，前缀乘积表+后缀乘积表,或许也不算动规
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int length = nums.size();
    vector<int> before(length);
    vector<int> after(length);
    int value = 1;
    int value2 = 1;
    for (int i = 0; i < length; i++) {
      value *= nums[i];
      value2 *= nums[length - 1 - i];
      before[i] = value;
      after[length - 1 - i] = value2;
    }
    vector<int> answer(length);
    for (int i = 0; i < length; i++) {
      if (i == 0) {
        answer[i] = after[i + 1];
      } else if (i == length - 1)
        answer[i] = before[i - 1];
      else
        answer[i] = after[i + 1] * before[i - 1];
    }
    return answer;
  }
};
// @lc code=end

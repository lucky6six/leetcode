/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 *
 * https://leetcode.cn/problems/binary-search/description/
 *
 * algorithms
 * Easy (55.17%)
 * Likes:    1547
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.2M
 * Testcase Example:  '[-1,0,3,5,9,12]\n9'
 *
 * 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target
 *  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
 *
 *
 * 示例 1:
 *
 * 输入: nums = [-1,0,3,5,9,12], target = 9
 * 输出: 4
 * 解释: 9 出现在 nums 中并且下标为 4
 *
 *
 * 示例 2:
 *
 * 输入: nums = [-1,0,3,5,9,12], target = 2
 * 输出: -1
 * 解释: 2 不存在 nums 中因此返回 -1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 你可以假设 nums 中的所有元素是不重复的。
 * n 将在 [1, 10000]之间。
 * nums 的每个元素都将在 [-9999, 9999]之间。
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    if (nums.size() == 0)
      return -1;
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] < target)
        left = mid + 1;
      else
        right = mid - 1;
    }
    return -1;
  }
};
// @lc code=end

// 大家写二分法经常写乱，主要是因为对区间的定义没有想清楚，区间的定义就是不变量。要在二分查找的过程中，
// 保持不变量，就是在while寻找中每一次边界的处理都要坚持根据区间的定义来操作，这就是循环不变量规则。
class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    int n = nums.size();
    // 第一种写法，我们定义 target 是在一个在左闭右闭的区间里，也就是[left,
    // right] （这个很重要非常重要）
    int left = 0;
    int right = n - 1;
    // while (left <= right) 要使用 <= ，因为left == right是有意义的，
    // 所以使用<= if (nums[middle] > target) right 要赋值为 middle - 1，
    // 因为当前这个nums[middle]一定不是target，
    // 那么接下来要查找的左区间结束下标位置就是 middle + 1
    // 若不进行这种+-1操作，可能当left = mid时卡住
    // 或right = mid卡住（当right = left = mid时死循环）
    while (left <= right)
    {
      int mid = (left + right) / 2;
      if (nums[mid] == target)
      {
        return mid;
      }
      if (nums[mid] < target)
      {
        left = mid + 1;
      }
      else
      {
        right = mid - 1;
      }
    }
    return -1;
  }
};

class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    int n = nums.size();
    // 第二种写法，我们定义 target
    // 是在一个在左闭右开的区间里，也就是[left,right)
    int left = 0;
    int right = n;
    // while (left < right)因为left == right无意义，
    // 所以使用<= if (nums[middle] > target) right 要赋值为
    // middle，开区间把middle排除了，
    // 那么接下来要查找的左区间结束下标位置就是middle + 1
    while (left < right)
    {
      int mid = (left + right) / 2;
      if (nums[mid] == target)
      {
        return mid;
      }
      if (nums[mid] < target)
      {
        left = mid + 1;
      }
      else
      {
        right = mid;
      }
    }
    return -1;
  }
};

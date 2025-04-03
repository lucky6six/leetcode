/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode.cn/problems/subsets/description/
 *
 * algorithms
 * Medium (81.26%)
 * Likes:    2281
 * Dislikes: 0
 * Total Accepted:    779.2K
 * Total Submissions: 958.9K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整数数组 nums ，数组中的元素 互不相同
 * 。返回该数组所有可能的子集（幂集）。
 *
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0]
 * 输出：[[],[0]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * nums 中的所有元素 互不相同
 *
 *
 */
// 一眼回溯
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> ret;
  vector<int> tmp;
  int size;
  //   vector<bool> visited;
  void mysubsets(vector<int> &nums, int index) {
    ret.push_back(tmp);
    if (tmp.size() == size) {
      return;
    }
    // 区分组合与排列
    // 组合中123和321不能同时出现，这反倒不需要visited数组，递时只遍历后续即可
    for (int i = index; i < size; i++) {
      //   if (visited[i] == false) {
      // visited[i] = true;
      tmp.push_back(nums[i]);
      mysubsets(nums, i + 1);
      tmp.pop_back();
      // visited[i] = false;
      //   }
    }
    return;
  }
  vector<vector<int>> subsets(vector<int> &nums) {
    size = nums.size();
    // visited.resize(size);
    mysubsets(nums, 0);
    return ret;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode.cn/problems/permutations/description/
 *
 * algorithms
 * Medium (80.14%)
 * Likes:    3053
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序
 * 返回答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1]
 * 输出：[[1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * nums 中的所有整数 互不相同
 *
 *
 */
// 一眼回溯1.标记数组，用额外空间标识未选择的数
// 2.每次选择一个数时，将该数移动到前面，每次只选后面的数（这种不是字典序）
#include <vector>
using namespace std;
//  @lc code=start
class Solution {
public:
  vector<vector<int>> ret;
  vector<int> tmp;
  vector<bool> visited;
  int size;
  void mypermute(vector<int> &nums) {
    // 终止条件
    if (tmp.size() == size) {
      ret.push_back(tmp);
      return;
    }
    for (int i = 0; i < size; i++) {
      if (visited[i] == false) {
        // 递归
        visited[i] = true;
        tmp.push_back(nums[i]);
        mypermute(nums);
        // 回溯
        tmp.pop_back();
        visited[i] = false;
      }
    }
    return;
  }
  vector<vector<int>> permute(vector<int> &nums) {
    size = nums.size();
    visited.resize(size);
    mypermute(nums);
    return ret;
  }
};
// @lc code=end

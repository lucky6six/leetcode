/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode.cn/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (59.46%)
 * Likes:    1539
 * Dislikes: 0
 * Total Accepted:    522.9K
 * Total Submissions: 879.8K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 *
 * candidates 中的每个数字在每个组合中只能使用 一次 。
 *
 * 注意：解集不能包含重复的组合。 
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 输出:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 *
 * 示例 2:
 *
 *
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 输出:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 *
 *
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<vector<int>> res;
  vector<int> path;
  vector<bool> used;
  int size;
  void dfs(vector<int> &candidates, int target, int index) {
    if (target == 0) {
      res.push_back(path);
      return;
    }
    if (target < 0) {
      return;
    }
    for (int i = index; i < size; i++) {
      //去重集合，同一树层的重复元素只取一个，这里是关键，递归到下层可以重复使用
      if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == true) {
        //防止多个重复元素，只取一个
        used[i] = true;
        continue;
      }
      //递归下层时不用设置used，因为下一树层可以重复使用不同位置的相同数字
      path.push_back(candidates[i]);
      //与题目39对比，只需要在这里改一下，i变成i+1，不允许重复，但另一方面，要求去除重复的组合
      dfs(candidates, target - candidates[i], i + 1);
      path.pop_back();
      //本层中的每次循环都要设置true，因为同一树层中不能重复使用相同数字，不然会有重复的组合
      used[i] = true;
    }
    //本层结束应该还原状态，将used[i]重新置为false
    fill(used.begin(), used.end(), false);
    return;
  }
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    size = candidates.size();
    // resize的使用，初始化为false
    used.resize(size, false);
    dfs(candidates, target, 0);
    return res;
  }
};
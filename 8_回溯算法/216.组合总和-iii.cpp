/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 *
 * https://leetcode.cn/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (71.03%)
 * Likes:    849
 * Dislikes: 0
 * Total Accepted:    378K
 * Total Submissions: 530.1K
 * Testcase Example:  '3\n7'
 *
 * 找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
 *
 *
 * 只使用数字1到9
 * 每个数字 最多使用一次 
 *
 *
 * 返回 所有可能的有效组合的列表
 * 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: k = 3, n = 7
 * 输出: [[1,2,4]]
 * 解释:
 * 1 + 2 + 4 = 7
 * 没有其他符合的组合了。
 *
 * 示例 2:
 *
 *
 * 输入: k = 3, n = 9
 * 输出: [[1,2,6], [1,3,5], [2,3,4]]
 * 解释:
 * 1 + 2 + 6 = 9
 * 1 + 3 + 5 = 9
 * 2 + 3 + 4 = 9
 * 没有其他符合的组合了。
 *
 * 示例 3:
 *
 *
 * 输入: k = 4, n = 1
 * 输出: []
 * 解释: 不存在有效的组合。
 * 在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 >
 * 1，没有有效的组合。
 *
 *
 *
 *
 * 提示:
 *
 *
 * 2 <= k <= 9
 * 1 <= n <= 60
 *
 *
 */
#include <vector>

using namespace std;
// tip:看起来需要嵌套变量k层循环的题目，都可以考虑回溯递归。
// @lc code=start
class Solution {
public:
  vector<vector<int>> res;
  //可选开始数字（终止数字为9），目标和，还剩几个数，当前路径，结果集
  void dfs(int start, int n, int k, vector<int> &path,
           vector<vector<int>> &res) {
    //终止条件
    if (k == 0 && n == 0) {
      res.push_back(path);
      return;
    } else if (k == 0 || n == 0) {
      //该路径不合理了，直接返回
      return;
    }
    //善于剪枝
    for (int i = start; i < 10 - k + 1; i++) {
      path.push_back(i);
      dfs(i + 1, n - i, k - 1, path, res);
      path.pop_back();
    }
    return;
  }
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> path;
    dfs(1, n, k, path, res);
    return res;
  }
};
// @lc code=end
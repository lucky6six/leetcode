/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode.cn/problems/combinations/description/
 *
 * algorithms
 * Medium (76.94%)
 * Likes:    1619
 * Dislikes: 0
 * Total Accepted:    702.7K
 * Total Submissions: 913.3K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 *
 * 你可以按 任何顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 4, k = 2
 * 输出：
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 * 示例 2：
 *
 *
 * 输入：n = 1, k = 1
 * 输出：[[1]]
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 *
 *
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
  //引用传递，减少vector的拷贝
  //反正需要手动pop当前循环的元素，值传递也失去了调用栈回溯的优势
  void dfs(int start, int n, int k, vector<int> &path,
           vector<vector<int>> &res) {
    //终止条件
    if (k == 0) {
      res.push_back(path);
      return;
    }
    //递归流程
    // ps:这里的i<=n-k+1是剪枝，因为后面的数不够了，就不用再遍历了
    //如果不剪枝，i<=n，也可以实现效果，但浪费时间
    for (int i = start; i <= n - k + 1; i++) {
      //加入路径，找下一个数
      path.push_back(i);
      dfs(i + 1, n, k - 1, path, res);
      path.pop_back();
    }
    return;
  }
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> path;
    //需要k层遍历，但k是变量，所以需要递归
    // for (int i = 1; i < n - k + 1; i++) {
    // }
    // ps:如果把res设置为类变量，就不用在递归函数里面传递res了
    dfs(1, n, k, path, res);
    return res;
  }
};
// @lc code=end

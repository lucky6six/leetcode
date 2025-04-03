/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode.cn/problems/word-search/description/
 *
 * algorithms
 * Medium (48.39%)
 * Likes:    1947
 * Dislikes: 0
 * Total Accepted:    635.3K
 * Total Submissions: 1.3M
 * Testcase Example:
 * '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word
 * 存在于网格中，返回 true ；否则，返回 false 。
 *
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCCED"
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "SEE"
 * 输出：true
 *
 *
 * 示例 3：
 *
 *
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCB"
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == board.length
 * n = board[i].length
 * 1
 * 1
 * board 和 word 仅由大小写英文字母组成
 *
 *
 *
 *
 * 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board
 * 更大的情况下可以更快解决问题？
 *
 */
// 一眼回溯，用visited记录用过的格子。对每个格子dfs，不断寻找又没next char
#include <vector>
using namespace std;
//  @lc code=start
class Solution {
  vector<vector<bool>> visited;

public:
  bool myexist(int i, int j, int index, string word,
               vector<vector<char>> &board) {
    // 已经找完，ok
    if (index >= word.size())
      return true;
    // 超界
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
      return false;
    // 已使用
    if (visited[i][j] == true)
      return false;
    // 不满足
    if (board[i][j] != word[index])
      return false;
    // 访问该值，寻找下一个值
    visited[i][j] = true;
    index++;
    bool ret = myexist(i - 1, j, index, word, board) ||
               myexist(i, j - 1, index, word, board) ||
               myexist(i + 1, j, index, word, board) ||
               myexist(i, j + 1, index, word, board);
    // 记得回溯
    index--;
    visited[i][j] = false;
    return ret;
  }

  bool exist(vector<vector<char>> &board, string word) {
    int m = board.size();
    int n = board[0].size();
    // 这里其实不用visit标记访问，可以直接将board中的字符改为“#”等特殊字符，在回溯时取消即可。
    visited.resize(m);
    // //值传递，并没有初始化
    // for (auto vec : visited) {
    //   vec.resize(n);
    // }
    for (int i = 0; i < m; i++) {
      visited[i].resize(n);
    }
    // visited.resize(m, vector<bool>(n, false)); // 正确初始化 visited 数组
    // 也可以使用
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (myexist(i, j, 0, word, board))
          return true;
      }
    }
    return false;
  }
};
// @lc code=end

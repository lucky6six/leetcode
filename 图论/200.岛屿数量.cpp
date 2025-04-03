/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode.cn/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (62.09%)
 * Likes:    2689
 * Dislikes: 0
 * Total Accepted:    999K
 * Total Submissions: 1.6M
 * Testcase Example:
 * '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和
 * '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 *
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 *
 * 此外，你可以假设该网格的四条边均被水包围。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * 输出：1
 *
 *
 * 示例 2：
 *
 *
 * 输入：grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * 输出：3
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1
 * grid[i][j] 的值为 '0' 或 '1'
 *
 *
 */
#include <vector>
using namespace std;
// 陷入了动态规划的误区，实际上可以通过DFS粗暴解决
//  class Solution {
//  public:
//    int numIslands(vector<vector<char>> &grid) {
//      int m = grid.size();
//      int n = grid[0].size();
//      int num = 0;
//      vector<vector<int>> nums(m, vector<int>(n, 0));
//      for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//          if ((i == 0 || grid[i - 1][j] == '0') &&
//              (j == 0 || grid[i][j - 1] == '0') && grid[i][j] == '1')
//            num++;
//        }
//      }
//      return num;
//    }
//  };

//  @lc code=start
class Solution {
public:
  void dfs(int i, int j, vector<vector<char>> &grid) {
    if (i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1)
      return;
    if (grid[i][j] == '1') {
      grid[i][j] = '2';
      dfs(i - 1, j, grid);
      dfs(i, j - 1, grid);
      dfs(i + 1, j, grid);
      dfs(i, j + 1, grid);
    }
    return;
  }
  int numIslands(vector<vector<char>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int num = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          num++;
          dfs(i, j, grid);
        }
      }
    }
    return num;
  }
};

// @lc code=end

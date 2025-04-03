/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 *
 * https://leetcode.cn/problems/rotting-oranges/description/
 *
 * algorithms
 * Medium (53.58%)
 * Likes:    981
 * Dislikes: 0
 * Total Accepted:    258.2K
 * Total Submissions: 481.9K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * 在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：
 *
 *
 * 值 0 代表空单元格；
 * 值 1 代表新鲜橘子；
 * 值 2 代表腐烂的橘子。
 *
 *
 * 每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。
 *
 * 返回
 * 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：grid = [[2,1,1],[1,1,0],[0,1,1]]
 * 输出：4
 *
 *
 * 示例 2：
 *
 *
 * 输入：grid = [[2,1,1],[0,1,1],[1,0,1]]
 * 输出：-1
 * 解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4
 * 个方向上。
 *
 *
 * 示例 3：
 *
 *
 * 输入：grid = [[0,2]]
 * 输出：0
 * 解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10
 * grid[i][j] 仅为 0、1 或 2
 *
 *
 */
// 可以规约为1.有路径联通2.距离最远
// 对每个烂橘子bfs，如果有橘子没访问：-1，否则返回bfs最深深度。
// 图遍历的一个关键问题时防止循环遍历
#include <vector>
using namespace std;

//  @lc code=start
class Solution {
public:
  int min_time[10][10]{INT_MAX};
  void bfs_1(int i, int j, int deep, vector<vector<int>> &grid) {
    deep++;
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
      return;
    // 当访问到新鲜橘子，且是访问时间更大的橘子才会继续递归（更新到小数，不会一直循环）
    if (grid[i][j] == 1 && deep < min_time[i][j]) {
      min_time[i][j] = deep;
      bfs_1(i + 1, j, deep, grid);
      bfs_1(i, j + 1, deep, grid);
      bfs_1(i - 1, j, deep, grid);
      bfs_1(i, j - 1, deep, grid);
    }
    return;
  }
  void bfs_2(int i, int j, vector<vector<int>> &grid) {
    bfs_1(i + 1, j, 0, grid);
    bfs_1(i, j + 1, 0, grid);
    bfs_1(i - 1, j, 0, grid);
    bfs_1(i, j - 1, 0, grid);
  }
  int orangesRotting(vector<vector<int>> &grid) {
    int ret = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        min_time[i][j] = INT_MAX;
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 2)
          bfs_2(i, j, grid);
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          if (min_time[i][j] == INT_MAX)
            return -1;
          else
            ret = max(ret, min_time[i][j]);
        }
      }
    }
    return ret;
  }
};
// @lc code=end

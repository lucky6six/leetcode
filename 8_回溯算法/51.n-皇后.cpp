/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 *
 * https://leetcode.cn/problems/n-queens/description/
 *
 * algorithms
 * Hard (75.18%)
 * Likes:    2253
 * Dislikes: 0
 * Total Accepted:    499.2K
 * Total Submissions: 663.9K
 * Testcase Example:  '4'
 *
 * 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
 *
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n
 * 的棋盘上，并且使皇后彼此之间不能相互攻击。
 *
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 *
 *
 *
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.'
 * 分别代表了皇后和空位。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 4
 * 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：[["Q"]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 9
 *
 *
 *
 *
 */
// 总结一下回溯问题，如果枚举时需要嵌套n次循环，那可能就要考虑回溯了，一般用于解决“复杂”问题
// 这里依旧是需要用额外空间记录每个位置合法性，回溯得到结果
#include <set>
#include <vector>
using namespace std;
//  @lc code=start
class Solution {
  vector<vector<string>> ret;
  vector<string> tmp;
  // 每次放置一个Q，都对后续放置添加了四个方向的限制，同一行的限制由遍历限制，剩下三个用set占据
  set<int> cols;
  set<int> dia1;
  set<int> dia2;

public:
  bool check(int row, int i) {
    if (cols.find(i) != cols.end())
      return false;
    if (dia1.find(i - row) != dia1.end())
      return false;
    if (dia2.find(i + row) != dia2.end())
      return false;
    return true;
  }
  void addcheck(int row, int i) {
    cols.insert(i);
    dia1.insert(i - row);
    dia2.insert(i + row);
    return;
  }
  void uncheck(int row, int i) {
    cols.erase(i);
    dia1.erase(i - row);
    dia2.erase(i + row);
    return;
  }
  void mysolveNQueens(int size, int row) {
    if (row == size) {
      ret.push_back(tmp);
      return;
    }
    for (int i = 0; i < size; i++) {
      if (check(row, i)) {
        string s = "";
        for (int j = 0; j < size; j++) {
          s = s + '.';
        }
        s[i] = 'Q';
        tmp.push_back(s);
        addcheck(row, i);
        // 每次决定该行的Q放置在哪
        mysolveNQueens(size, row + 1);
        uncheck(row, i);
        tmp.pop_back();
      }
    }
    return;
  }
  vector<vector<string>> solveNQueens(int n) {
    mysolveNQueens(n, 0);
    return ret;
  }
};
// @lc code=end

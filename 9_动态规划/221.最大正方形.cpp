/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 *
 * https://leetcode.cn/problems/maximal-square/description/
 *
 * algorithms
 * Medium (51.09%)
 * Likes:    1754
 * Dislikes: 0
 * Total Accepted:    371.6K
 * Total Submissions: 727.3K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * 输出：4
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [["0","1"],["1","0"]]
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：matrix = [["0"]]
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1
 * matrix[i][j] 为 '0' 或 '1'
 *
 *
 */
// 动态规划，填二维表格
#include <vector>
using namespace std;
//  @lc code=start
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {

        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int rows = matrix.size();
        int columns = matrix[0].size();
        int maxsize = 0;
        vector<vector<int>> dp(rows, vector<int>(columns));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (matrix[i][j] == '0')
                {
                    dp[i][j] = 0;
                    continue;
                }
                else if (i == 0 || j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    // min只能用于二者对比
                    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
                }

                if (dp[i][j] > maxsize)
                {
                    maxsize = dp[i][j];
                }
            }
        }
        return maxsize * maxsize;
    }
};
// @lc code=end

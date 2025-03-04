/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode.cn/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (51.04%)
 * Likes:    2515
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2.1M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti,
 * endi]
 * 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出：[[1,6],[8,10],[15,18]]
 * 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 *
 *
 * 示例 2：
 *
 *
 * 输入：intervals = [[1,4],[4,5]]
 * 输出：[[1,5]]
 * 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ret;
    bool flag = 0;
    int begin = -1, end = -1;

    for (auto arr : intervals) {
      if (arr[0] <= end) {
        end = max(end, arr[1]);
      } else {
        if (end != -1) {
          vector<int> tmp;
          tmp.push_back(begin);
          tmp.push_back(end);
          ret.push_back(tmp);
        }
        begin = arr[0];
        end = arr[1];
      }
    }
    vector<int> tmp;
    tmp.push_back(begin);
    tmp.push_back(end);
    ret.push_back(tmp);
    return ret;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 *
 * https://leetcode.cn/problems/partition-labels/description/
 *
 * algorithms
 * Medium (78.05%)
 * Likes:    1248
 * Dislikes: 0
 * Total Accepted:    314.2K
 * Total Submissions: 402.6K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * 给你一个字符串 s
 * 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。例如，字符串 "ababcc"
 * 能够被分为 ["abab", "cc"]，但类似 ["aba", "bcc"] 或 ["ab", "ab", "cc"]
 * 的划分是非法的。
 *
 * 注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。
 *
 * 返回一个表示每个字符串片段的长度的列表。
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "ababcbacadefegdehijhklij"
 * 输出：[9,7,8]
 * 解释：
 * 划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
 * 每个字母最多出现在一个片段中。
 * 像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。
 *
 * 示例 2：
 *
 *
 * 输入：s = "eccbbbbdec"
 * 输出：[10]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 500
 * s 仅由小写英文字母组成
 *
 *
 */
// 反正都要提前遍历一边，可以直接记录每个字母最后一次出现的位置！
#include <string>
#include <vector>
using namespace std;
//  @lc code=start
class Solution {
public:
  vector<int> partitionLabels(string s) {
    int last_pos[26];
    int size = s.size();
    for (int i = 0; i < size; i++) {
      last_pos[s[i] - 'a'] = i;
    }
    int pos, end = 0;
    int begin = 0;
    vector<int> ret;
    while (begin < size) {
      pos = begin;
      do {
        end = max(end, last_pos[s[pos] - 'a']);
        pos++;
      } while (pos < end);
      ret.push_back(end - begin + 1);
      begin = end + 1;
    }
    return ret;
  }
};
// 官解中写法更优雅
//  class Solution {
//      public:
//          vector<int> partitionLabels(string s) {
//              int last[26];
//              int length = s.size();
//              for (int i = 0; i < length; i++) {
//                  last[s[i] - 'a'] = i;
//              }
//              vector<int> partition;
//              int start = 0, end = 0;
//              for (int i = 0; i < length; i++) {
//                  end = max(end, last[s[i] - 'a']);
//                  if (i == end) {
//                      partition.push_back(end - start + 1);
//                      start = end + 1;
//                  }
//              }
//              return partition;
//          }
//      };
//  @lc code=end

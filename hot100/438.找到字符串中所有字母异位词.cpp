/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (53.85%)
 * Likes:    1610
 * Dislikes: 0
 * Total Accepted:    605.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定两个字符串 s 和
 * p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "abab", p = "ab"
 * 输出: [0,1,2]
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= s.length, p.length <= 3 * 10^4
 * s 和 p 仅包含小写字母
 *
 *
 */
// 一眼滑动窗口，可以优化(用hash（map）记录差距值)
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  bool check(int arr[]) {
    for (int i = 0; i < 26; i++) {
      if (arr[i] != 0)
        return false;
    }
    return true;
  }
  vector<int> findAnagrams(string s, string p) {
    vector<int> ret;
    int size_p = p.size();
    int size_s = s.size();
    if (size_p > size_s)
      return ret;
    int arr[26] = {0};
    for (auto s : p) {
      arr[s - 'a']++;
    }

    for (int i = 0; i < size_p; i++) {
      arr[s[i] - 'a']--;
    }
    int i;
    for (i = 0; i < size_s - size_p; i++) {
      if (check(arr)) {
        ret.push_back(i);
      }
      arr[s[i] - 'a']++;
      arr[s[i + size_p] - 'a']--;
    }
    if (check(arr)) {
      ret.push_back(i);
    }
    return ret;
  }
};
// @lc code=end

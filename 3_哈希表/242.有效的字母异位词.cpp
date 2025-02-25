/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode.cn/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (66.33%)
 * Likes:    910
 * Dislikes: 0
 * Total Accepted:    759.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 *
 * 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "rat", t = "car"
 * 输出: false
 *
 *
 *
 * 提示:
 *
 *
 * 1
 * s 和 t 仅包含小写字母
 *
 *
 *
 *
 * 进阶: 如果输入字符串包含 unicode
 * 字符怎么办？你能否调整你的解法来应对这种情况？
 *
 */
#include <string>
using namespace std;
//记录出现次数，常见hash表（表格形式！）
// @lc code=start
class Solution {
public:
  bool isAnagram(string s, string t) {
    //这里的数据类型决定了每种字母可以出现的上限，数量超上限可能出现误判。
    int _s[26] = {0}, _t[26] = {0};
    int length = s.size();
    if (t.size() != length)
      return false;
    //此处可优化掉t[]，节省空间，改为对s[]内的元素做--;
    for (int i = 0; i < length; i++) {
      //不用记ascii码，直接-a得相对位置。
      _s[s[i] - 'a']++;
      _t[t[i] - 'a']++;
    }
    for (int j = 0; j < 26; j++) {
      if (_s[j] != _t[j])
        return false;
    }
    return true;
  }
};
// @lc code=end

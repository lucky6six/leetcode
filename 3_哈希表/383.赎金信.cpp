/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 *
 * https://leetcode.cn/problems/ransom-note/description/
 *
 * algorithms
 * Easy (63.60%)
 * Likes:    875
 * Dislikes: 0
 * Total Accepted:    470.4K
 * Total Submissions: 736K
 * Testcase Example:  '"a"\n"b"'
 *
 * 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine
 * 里面的字符构成。
 *
 * 如果可以，返回 true ；否则返回 false 。
 *
 * magazine 中的每个字符只能在 ransomNote 中使用一次。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：ransomNote = "a", magazine = "b"
 * 输出：false
 *
 *
 * 示例 2：
 *
 *
 * 输入：ransomNote = "aa", magazine = "ab"
 * 输出：false
 *
 *
 * 示例 3：
 *
 *
 * 输入：ransomNote = "aa", magazine = "aab"
 * 输出：true
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= ransomNote.length, magazine.length <= 10^5
 * ransomNote 和 magazine 由小写英文字母组成
 *
 *
 */
#include <string>
using namespace std;
//思路：分别用数组（hash表）统计，判断包含（大于）关系
// @lc code=start
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    int ran[26] = {0}, mag[26] = {0};
    for (char i : ransomNote) {
      ran[i - 'a']++;
    }
    for (char i : magazine) {
      mag[i - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (ran[i] > mag[i])
        return false;
    }
    return true;
  }
};
// @lc code=end

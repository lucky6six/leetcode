/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找共用字符
 *
 * https://leetcode.cn/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (70.31%)
 * Likes:    366
 * Dislikes: 0
 * Total Accepted:    93.8K
 * Total Submissions: 133.4K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * 给你一个字符串数组 words ，请你找出所有在 words
 * 的每个字符串中都出现的共用字符（ 包括重复字符），并以数组形式返回。你可以按
 * 任意顺序 返回答案。
 *
 *
 * 示例 1：
 *
 *
 * 输入：words = ["bella","label","roller"]
 * 输出：["e","l","l"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：words = ["cool","lock","cook"]
 * 输出：["c","o"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 100
 * words[i] 由小写英文字母组成
 *
 *
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
// key值可以用自然数表示的table用数组，不能的可以用map，26个字母，可以直接用大小为26的数组
class Solution {
public:
  //别想太多，就两个比较，迭代对比吧，就是暴力。
  vector<string> commonChars(vector<string> &words) {
    int table[26] = {0};
    for (int i = 0; i < words[0].size(); i++) {
      table[words[0][i] - 'a']++;
    }
    int comp[26] = {0};
    for (int index = 1; index < words.size(); index++) {
      std::fill(comp, comp + 26, 0);
      for (int i = 0; i < words[index].size(); i++) {
        comp[words[index][i] - 'a']++;
      }
      for (int i = 0; i < 26; i++) {
        table[i] = min(table[i], comp[i]);
      }
    }
    vector<string> ret;
    for (int i = 0; i < 26; i++) {
      while (table[i] > 0) {
        table[i]--;
        // char转string
        ret.push_back(string(1, 'a' + i));
      }
    }
    return ret;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 *
 * https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 *
 * algorithms
 * Easy (43.43%)
 * Likes:    2196
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 2.4M
 * Testcase Example:  '"sadbutsad"\n"sad"'
 *
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle
 * 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack
 * 的一部分，则返回  -1 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：haystack = "sadbutsad", needle = "sad"
 * 输出：0
 * 解释："sad" 在下标 0 和 6 处匹配。
 * 第一个匹配项的下标是 0 ，所以返回 0 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：haystack = "leetcode", needle = "leeto"
 * 输出：-1
 * 解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= haystack.length, needle.length <= 10^4
 * haystack 和 needle 仅由小写英文字符组成
 *
 *
 */
#include <string>
#include <vector>
using namespace std;
// 本题实现不参考代码随想录
// @lc code=start
class Solution {
public:
  //求出need串的next数组
  //前缀表统一减一的实现
  void getNext(int *next, const string &s) {
    //当前共同前后缀长度
    int j = 0;
    if (s[0])
      //初始置零，迭代终止条件
      next[0] = 0;
    //当前判断的next位置
    int i = 1;
    int length = s.size();
    while (i < length) {
      //前后缀相等，++
      if (s[j] == s[i]) {
        j++;
        next[i] = j;
        i++;
        //递归终止
      } else if (j == 0) {
        next[i] = j;
        i++;
        //找公共前后缀的前后缀
      } else {
        j = next[j - 1];
      }
    }
    return;
  }
  int strStr(string haystack, string needle) {
    //子串索引与长度
    int j = 0, to_length = needle.size();
    //初始化并获取next数组
    int *next = new int[to_length];
    getNext(next, needle);
    //主串长度
    int length = haystack.size();

    for (int i = 0; i < length; i++) {
      //相等，二者++继续匹配
      if (haystack[i] == needle[j]) {
        j++;
        //不相等的终止条件，即字串索引在句首，主串移动一位
      } else if (j == 0) {
        continue;
        //不相等时，找公共前后缀内的前后缀，尽可能移动字串。
      } else {
        j = next[j - 1];
        //主串不动，继续匹配
        i--;
      }
      //匹配长度等于字串长度
      if (j == to_length)
        //返回索引
        return i - j + 1;
    }
    return -1;
  }
};
//@lc code=end

/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 *
 * https://leetcode.cn/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (54.46%)
 * Likes:    1137
 * Dislikes: 0
 * Total Accepted:    548.8K
 * Total Submissions: 1M
 * Testcase Example:  '"the sky is blue"'
 *
 * 给你一个字符串 s ，请你反转字符串中 单词 的顺序。
 *
 * 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词
 * 分隔开。
 *
 * 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
 *
 * 注意：输入字符串
 * s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "the sky is blue"
 * 输出："blue is sky the"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "  hello world  "
 * 输出："world hello"
 * 解释：反转后的字符串中不能存在前导空格和尾随空格。
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "a good   example"
 * 输出："example good a"
 * 解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^4
 * s 包含英文大小写字母、数字和空格 ' '
 * s 中 至少存在一个 单词
 *
 *
 *
 *
 *
 *
 *
 * 进阶：如果字符串在你使用的编程语言中是一种可变数据类型，请尝试使用 O(1)
 * 额外空间复杂度的 原地 解法。
 *
 */

//熟练使用多次反转，类比右旋字符串，先反转整个句子，再反转每个单词，同时删除多余空格
// erase本身即O（n）复杂度，不合适。
//去重是数组类修改变换操作，联想到快慢指针法
#include <algorithm>
#include <string>

using namespace std;
class Solution {
public:
  string reverseWords(string s) {
    reverse(s.begin(), s.end());
    int left = 0, right = 0;
    int length = s.size();
    while (left < length && s[left] == ' ') {
      s.erase(left, 1);
      length--;
      // left++;
    }
    while (left < length) {
      while (right < length && s[right] != ' ')
        right++;
      reverse(s.begin() + left, s.begin() + right);
      left = right + 1;
      while (left < length && s[left] == ' ') {
        s.erase(left, 1);
        length--;
        // left++;
      }
      right = left;
    }
    while (right == length && s[right - 1] == ' ') {
      s.erase(right - 1, 1);
      length--;
      // left++;
    }
    return s;
  }
};
// @lc code=start
//记得双指针擅长对数组类型的数据进行低时空复杂度的修改。
//可以先不管空格，翻转s，之后用双指针法遍历一遍，in-place慢指针拷贝。
class Solution {
public:
  string reverseWords(string s) {
    reverse(s.begin(), s.end());
    int left = 0, right = 0;
    int length = s.size();
    while (left < length) {
      while (right < length && s[right] != ' ')
        right++;
      reverse(s.begin() + left, s.begin() + right);
      left = right + 1;
      right = left;
    }
    //双指针去重
    left = 0;
    right = 0;
    while (s[right] == ' ') {
      right++;
    }
    while (right < length) {
      s[left] = s[right];
      left++;
      right++;
      while (right < length && s[right] == s[right - 1] && s[right] == ' ') {
        right++;
      }
    }
    //勿忘首尾经常是特殊情况
    if (s[left - 1] == ' ') {
      s.resize(left - 1);
    } else
      s.resize(left);
    return s;
  }
};

// @lc code=end

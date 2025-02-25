/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 *
 * https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/
 *
 * algorithms
 * Easy (72.34%)
 * Likes:    621
 * Dislikes: 0
 * Total Accepted:    299.4K
 * Total Submissions: 413.7K
 * Testcase Example:  '"abbaca"'
 *
 * 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
 *
 * 在 S 上反复执行重复项删除操作，直到无法继续删除。
 *
 * 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
 *
 *
 *
 * 示例：
 *
 * 输入："abbaca"
 * 输出："ca"
 * 解释：
 * 例如，在 "abbaca" 中，我们可以删除 "bb"
 * 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串
 * "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= S.length <= 20000
 * S 仅由小写英文字母组成。
 *
 *
 */
#include <stack>
#include <string>
using namespace std;
//迭代删除，此题易得。考虑能否一次遍历，用栈操作即可。
//用栈最后要倒出来，其实双端队列更合适(x)
//用栈也可以，从后向前填充ret就行
//或者得到倒序的string 用reverse反转
// @lc code=start
class Solution {
public:
  stack<char> st, ret;
  string removeDuplicates(string s) {
    for (char a : s) {
      if (st.empty() || st.top() != a) {
        st.push(a);
      } else {
        st.pop();
      }
    }
    int size = st.size();
    s.resize(size);
    while (size > 0) {
      size--;
      s[size] = st.top();
      st.pop();
    }
    return s;
  }
};
// @lc code=end

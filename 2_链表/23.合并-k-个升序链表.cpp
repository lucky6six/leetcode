/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 *
 * https://leetcode.cn/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (61.28%)
 * Likes:    2964
 * Dislikes: 0
 * Total Accepted:    940.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 *
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 *
 *
 *
 * 示例 1：
 *
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 *
 *
 * 示例 2：
 *
 * 输入：lists = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 * 输入：lists = [[]]
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
 *
 *
 */
#include <queue>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 优先级队列
//  @lc code=start

class Solution {
public:
  struct comp {
    bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
  };
  priority_queue<ListNode *, vector<ListNode *>, comp> q;
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    for (auto list : lists) {
      if (list)
        q.push(list);
    }
    ListNode *ret = new ListNode(0);
    ListNode *tmp = ret;
    while (!q.empty()) {
      ListNode *node = q.top();
      q.pop();
      tmp->next = node;
      tmp = tmp->next;
      if (node->next)
        q.push(node->next);
    }
    return ret->next;
  }
};
// @lc code=end

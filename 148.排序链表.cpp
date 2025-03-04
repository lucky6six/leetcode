/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode.cn/problems/sort-list/description/
 *
 * algorithms
 * Medium (66.67%)
 * Likes:    2457
 * Dislikes: 0
 * Total Accepted:    634.5K
 * Total Submissions: 951.7K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [4,2,1,3]
 * 输出：[1,2,3,4]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [-1,5,3,4,0]
 * 输出：[-1,0,3,4,5]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目在范围 [0, 5 * 10^4] 内
 * -10^5 <= Node.val <= 10^5
 *
 *
 *
 *
 * 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
 *
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 二分归并，自顶向下递归，需要栈空间，自底向上迭代，代码可读性差
//  @lc code=start

class Solution {
public:
  ListNode *merge(ListNode *list1, ListNode *list2) {
    ListNode *ret = new ListNode();
    ListNode *tmp = ret;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        // tmp->next = new ListNode(list1->val);
        // tmp = tmp->next;
        tmp->next = list1;
        list1 = list1->next;
      } else {
        // tmp->next = new ListNode(list2->val);
        tmp->next = list2;
        list2 = list2->next;
      }
      tmp = tmp->next;
    }

    // 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
    tmp->next = list1 == nullptr ? list2 : list1;

    return ret->next;
  }
  ListNode *sortListSub(ListNode *head, ListNode *tail) {
    if (head == tail)
      return nullptr;
    if (head->next == tail) {
      head->next = nullptr;
      return head;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != tail) {
      slow = slow->next;
      fast = fast->next;
      if (fast != tail) {
        fast = fast->next;
      }
    }
    ListNode *list1 = sortListSub(head, slow);
    ListNode *list2 = sortListSub(slow, fast);
    return merge(list1, list2);
  };
  ListNode *sortList(ListNode *head) { return sortListSub(head, nullptr); }
};
// @lc code=end

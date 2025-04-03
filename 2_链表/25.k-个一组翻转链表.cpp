/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode.cn/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (69.03%)
 * Likes:    2497
 * Dislikes: 0
 * Total Accepted:    738.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
 *
 * k
 * 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 *
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4,5], k = 2
 * 输出：[2,1,4,3,5]
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：head = [1,2,3,4,5], k = 3
 * 输出：[3,2,1,4,5]
 *
 *
 *
 * 提示：
 *
 *
 * 链表中的节点数目为 n
 * 1 <= k <= n <= 5000
 * 0 <= Node.val <= 1000
 *
 *
 *
 *
 * 进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？
 *
 *
 *
 *
 */
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 在头节点之前设置一个节点，便于统一循环和记录返回值。
//  @lc code=start

class Solution {
public:
  pair<ListNode *, ListNode *> reversek(ListNode *head, ListNode *tail) {
    ListNode *prev = tail->next;
    ListNode *p = head;
    while (prev != tail) {
      ListNode *nex = p->next;
      p->next = prev;
      prev = p;
      p = nex;
    }
    return {tail, head};
  }
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *hair = new ListNode(0);
    hair->next = head;
    ListNode *prev = hair;

    while (head) {
      ListNode *tail = prev;
      // 查看剩余部分长度是否大于等于 k
      for (int i = 0; i < k; ++i) {
        tail = tail->next;
        if (!tail) {
          return hair->next;
        }
      }
      ListNode *nex = tail->next;
      pair<ListNode *, ListNode *> result = reversek(head, tail);
      head = result.first;
      tail = result.second;
      // 把子链表重新接回原链表
      prev->next = head;
      tail->next = nex;
      prev = tail;
      head = tail->next;
    }

    return hair->next;
  }
};
// @lc code=end

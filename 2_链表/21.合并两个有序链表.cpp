/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode.cn/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (67.47%)
 * Likes:    3696
 * Dislikes: 0
 * Total Accepted:    2M
 * Total Submissions: 2.9M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序
 * 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
 * 输出：[1,1,2,3,4,4]
 *
 *
 * 示例 2：
 *
 *
 * 输入：l1 = [], l2 = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：l1 = [], l2 = [0]
 * 输出：[0]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 两个链表的节点数目范围是 [0, 50]
 * -100
 * l1 和 l2 均按 非递减顺序 排列
 *
 *
 */

// #include<>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *ret = new ListNode();
    ListNode *tmp = ret;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        tmp->next = new ListNode(list1->val);
        tmp = tmp->next;
        list1 = list1->next;
      } else {
        tmp->next = new ListNode(list2->val);
        tmp = tmp->next;
        list2 = list2->next;
      }
    }
    // 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
    tmp->next = list1 == nullptr ? list2 : list1;

    return ret->next;
  }
};
// @lc code=end

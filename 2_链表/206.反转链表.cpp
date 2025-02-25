/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode.cn/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (74.09%)
 * Likes:    3547
 * Dislikes: 0
 * Total Accepted:    1.8M
 * Total Submissions: 2.5M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [1,2]
 * 输出：[2,1]
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
 * 链表中节点的数目范围是 [0, 5000]
 * -5000
 *
 *
 *
 *
 * 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
 *
 *
 *
 */

// @lc code=start
// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// class Solution {
// public:
//   ListNode *reverseList(ListNode *head) {
//     //担心丢失前向数据时，多创建变量记录即可（也可理解为用多指针进行迭代）
//     ListNode *pre = nullptr;
//     ListNode *cur = head;
//     ListNode *tmp;
//     //本题建议画图进行流程表达，明确过程与终止条件。也可做为指针指代的练习，记住指针赋值为指向同一地址。
//     while (cur) {
//       tmp = cur->next;
//       cur->next = pre;
//       pre = cur;
//       cur = tmp;
//     }
//     head = pre;
//     return head;
//   }
// };

//递归方式
class Solution {
  //多品味一下递归的写法
public:
  ListNode *reverse(ListNode *pre, ListNode *cur) {
    if (cur) {
      ListNode *tmp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = tmp;
      //记得return
      return reverse(pre, cur);
    }
    return pre;
  }
  ListNode *reverseList(ListNode *head) {
    head = reverse(nullptr, head);
    return head;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode.cn/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (56.27%)
 * Likes:    1404
 * Dislikes: 0
 * Total Accepted:    706.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val ==
 * val 的节点，并返回 新的头节点 。
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,6,3,4,5,6], val = 6
 * 输出：[1,2,3,4,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [], val = 1
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = [7,7,7,7], val = 7
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 列表中的节点数目在范围 [0, 10^4] 内
 * 1
 * 0
 *
 *
 */

// @lc code=start
/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    //先令head != val
    while (head) {
      if (head->val == val) {
        ListNode *tmp = head;
        head = head->next;
        delete tmp;
      } else {
        //注意不要忘记while的终止条件！！！
        break;
      }
    }
    ListNode *p = head;
    //永远记得检测p的存在性，宁麻烦不放过
    while (p && p->next) {
      if (p->next->val == val) {
        ListNode *tmp = p->next;
        p->next = p->next->next;
        delete tmp;
      } else {
        p = p->next;
      }
    }
    return head;
  }
};

// //可以考虑设置一个虚拟头节点（在head前面），消掉head的特殊性进行处理
// class Solution {
// public:
//   ListNode *removeElements(ListNode *head, int val) {
//     ListNode *dummyHead = new ListNode(0); // 设置一个虚拟头结点
//     dummyHead->next = head; // 将虚拟头结点指向head，这样方便后面做删除操作
//     ListNode *cur = dummyHead;
//     while (cur->next != NULL) {
//       if (cur->next->val == val) {
//         ListNode *tmp = cur->next;
//         cur->next = cur->next->next;
//         // c/c++记得delete分配出来的空间结构
//         delete tmp;
//       } else {
//         cur = cur->next;
//       }
//     }
//     head = dummyHead->next;
//     delete dummyHead;
//     return head;
//   }
// };
// @lc code=end

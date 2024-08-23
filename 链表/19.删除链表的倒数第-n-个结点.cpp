/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 *
 * https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (47.48%)
 * Likes:    2839
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 2.9M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4,5], n = 2
 * 输出：[1,2,3,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [1], n = 1
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = [1,2], n = 1
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中结点的数目为 sz
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 *
 *
 *
 *
 * 进阶：你能尝试使用一趟扫描实现吗？
 *
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start

//双指针的经典应用，如果要删除倒数第n个节点，让fast移动n步，然后让fast和slow同时移动，
//直到fast指向链表末尾。删掉slow所指向的节点就可以了。

//思考历程：遍历一遍能够得到链表长度，进而得到倒数第n个节点的index，
//但单链表无法回过头找到index需要二次遍历，如何在第一次遍历就找到它呢？
// tip：观察不变量，index与链表尾相差n不变，可利用双指针构建长度为n的窗口
class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *high = head;
    ListNode *low = head;
    while (n > 0) {
      high = high->next;
      n--;
    }
    // high->val有意义，有值

    //当high移动到了nullptr而非一个具体的节点时，即删除头节点，即长度不支持窗口。
    //若采用创建虚拟头节点的方式则无需考虑该问题。
    if (!high) {
      head = head->next;
      return head;
    }
    while (high->next) {
      high = high->next;
      low = low->next;
    }
    ListNode *tmp;
    tmp = low->next;
    if (low->next) {
      low->next = low->next->next;
    } else {
      low->next = nullptr;
    }
    delete tmp;
    return head;
  }
};
// @lc code=end

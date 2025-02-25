/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode.cn/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (72.04%)
 * Likes:    2185
 * Dislikes: 0
 * Total Accepted:    819.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4]
 * 输出：[2,1,4,3]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = [1]
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目在范围 [0, 100] 内
 * 0 <= Node.val <= 100
 *
 *
 */
//把不想提交到leetcode的代码放在@lc前即可
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
  ListNode *swapPairs(ListNode *head) {
    //多用几个指针记录后继即可解决，链表指针操作记得多画图
    //利用虚拟头节点消去特殊性
    ListNode *tmp;
    ListNode *dummyHead = new ListNode(0, head);
    ListNode *p = dummyHead;
    while (p->next && p->next->next) {
      tmp = p->next;
      //画图明确三步走，想清楚再写
      p->next = p->next->next;
      tmp->next = tmp->next->next;
      p->next->next = tmp;
      //使用while注意迭代变化条件
      p = p->next->next;
    }
    //注意head指向的节点可能不再是要返回的头节点。尤其在使用dummyHead时。
    return dummyHead->next;
  }
};
// @lc code=end

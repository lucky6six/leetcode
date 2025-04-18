/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (75.08%)
 * Likes:    1800
 * Dislikes: 0
 * Total Accepted:    588.4K
 * Total Submissions: 783.6K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给你二叉树的根结点 root ，请你将它展开为一个单链表：
 *
 *
 * 展开后的单链表应该同样使用 TreeNode ，其中 right
 * 子指针指向链表中下一个结点，而左子指针始终为 null 。
 * 展开后的单链表应该与二叉树 先序遍历 顺序相同。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,5,3,4,null,6]
 * 输出：[1,null,2,null,3,null,4,null,5,null,6]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [0]
 * 输出：[0]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中结点数在范围 [0, 2000] 内
 * -100
 *
 *
 *
 *
 * 进阶：你可以使用原地算法（O(1) 额外空间）展开这棵树吗？
 *
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
// 原地展开实际上就是把右子树嫁接到左子树点最右端
//  @lc code=start

class Solution {
public:
  void flatten(TreeNode *root) {
    TreeNode *prev;
    while (root) {
      // 左侧空了，下一步
      if (root->left == nullptr) {
        root = root->right;
        continue;
      }
      // 右侧空了，左移动右
      if (root->right == nullptr) {
        root->right = root->left;
        root->left = nullptr;
      }
      // 左右不空，右嫁接左
      else {
        prev = root->left;
        while (prev->right)
          prev = prev->right;
        prev->right = root->right;
        root->right = nullptr;
      }
    }
    return;
  }
};
// @lc code=end

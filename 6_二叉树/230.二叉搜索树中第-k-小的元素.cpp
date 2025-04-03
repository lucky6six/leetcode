/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素
 *
 * https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (78.89%)
 * Likes:    951
 * Dislikes: 0
 * Total Accepted:    481.3K
 * Total Submissions: 609.9K
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * 给定一个二叉搜索树的根节点 root ，和一个整数 k
 * ，请你设计一个算法查找其中第 k 小的元素（从 1 开始计数）。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,1,4,null,2], k = 1
 * 输出：1
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [5,3,6,2,4,null,null,1], k = 3
 * 输出：3
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中的节点数为 n 。
 * 1 <= k <= n <= 10^4
 * 0 <= Node.val <= 10^4
 *
 *
 *
 *
 * 进阶：如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k
 * 小的值，你将如何优化算法？
 *
 */
#include <stack>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
// 二叉搜索树的中序遍历是按照键增加的顺序进行的。
// 进阶：1.建立平衡二叉搜索树 / 2.标记子树节点数量
// 迭代中序遍历实质上是借用栈，和递归一样，左子树依次入栈，出栈时将右子树入栈
//  @lc code=start
class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    stack<TreeNode *> s;
    //
    while (root || s.size() > 0) {
      // 遍历左子树
      while (root) {
        s.push(root);
        root = root->left;
      }
      // 访问该节点
      k--;
      root = s.top();
      if (k == 0)
        break;
      s.pop();
      // 遍历该节点右子树
      root = root->right;
    }
    return root->val;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (77.47%)
 * Likes:    1818
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 1.7M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树 root ，返回其最大深度。
 *
 * 二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：3
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,null,2]
 * 输出：2
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数量在 [0, 10^4] 区间内。
 * -100 <= Node.val <= 100
 *
 *
 */
#include <algorithm>
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

//递归思路，左右子树的最大深度+1（深搜）
class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr)
      return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};
// @lc code=start

//直观思路，层序遍历，得到层数（广搜）
class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr)
      return 0;
    queue<TreeNode *> q;
    q.push(root);
    int depth = 0;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        TreeNode *node = q.front();
        q.pop();
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      depth++;
    }
    return depth;
  }
};
// @lc code=end

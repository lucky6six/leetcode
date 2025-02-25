/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (53.84%)
 * Likes:    1183
 * Dislikes: 0
 * Total Accepted:    680.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 *
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 *
 * 说明：叶子节点是指没有子节点的节点。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [2,null,3,null,4,null,5,null,6]
 * 输出：5
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数的范围在 [0, 10^5] 内
 * -1000
 *
 *
 */
#include <algorithm>
//二叉树节点
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

//此方案不行，因为并非左右子节点有一个null就返回1，而是左右子节点都为null才返回1
// class Solution {
// public:
//   int minDepth(TreeNode *root) {
//     if (root == nullptr)
//       return 0;
//     return min(minDepth(root->left), minDepth(root->right)) + 1;
//   }
// };

// 注意这里最小深度是从根节点到最近叶子节点的最短路径上的节点数量。注意是叶子节点。

//     什么是叶子节点，左右孩子都为空的节点才是叶子节点！

//         求二叉树的最小深度和求二叉树的最大深度的差别主要在于处理左右孩子不为空的逻辑。
// @lc code=start
class Solution {
public:
  int minDepth(TreeNode *root) {
    if (root == nullptr)
      return 0;
    if (root->left == nullptr)
      return minDepth(root->right) + 1;
    if (root->right == nullptr)
      return minDepth(root->left) + 1;
    //只有当两个子节点都不为空时，才依据二者最小值++
    return min(minDepth(root->left), minDepth(root->right)) + 1;
  }
};
// @lc code=end

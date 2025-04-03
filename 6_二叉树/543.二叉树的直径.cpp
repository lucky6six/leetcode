/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 *
 * https://leetcode.cn/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (62.11%)
 * Likes:    1670
 * Dislikes: 0
 * Total Accepted:    542.2K
 * Total Submissions: 872.8K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你一棵二叉树的根节点，返回该树的 直径 。
 *
 * 二叉树的 直径 是指树中任意两个节点之间最长路径的 长度
 * 。这条路径可能经过也可能不经过根节点 root 。
 *
 * 两节点之间路径的 长度 由它们之间边数表示。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,3,4,5]
 * 输出：3
 * 解释：3 ，取路径 [4,2,1,3] 或 [5,2,1,3] 的长度。
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [1, 10^4] 内
 * -100 <= Node.val <= 100
 *
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
#include <vector>
using namespace std;
// 简单思考，规约为最大左右子树深度和。可以递归求解
//  @lc code=start

class Solution {
public:
  int ret = 0;
  // 从根节点开始，求深度
  int diameter(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int l = diameter(root->left);
    int r = diameter(root->right);
    ret = max(ret, l + r);
    return max(l, r) + 1;
  }

  int diameterOfBinaryTree(TreeNode *root) {
    if (root == nullptr)
      return 0;
    diameter(root);
    return ret;
  }
};
// @lc code=end

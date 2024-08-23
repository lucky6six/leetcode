/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 *
 * https://leetcode.cn/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (58.31%)
 * Likes:    1501
 * Dislikes: 0
 * Total Accepted:    604.7K
 * Total Submissions: 1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是 平衡二叉树  
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,2,3,3,null,null,4,4]
 * 输出：false
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = []
 * 输出：true
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中的节点数在范围 [0, 5000] 内
 * -10^4 <= Node.val <= 10^4
 *
 *
 */
//二叉树节点
// max函数
#include <algorithm>
// abs绝对值
#include <cmath>
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

// @lc code=start
//从平衡二叉树的定义出发，平衡二叉树的左右子树高度差不超过1，且左右子树也是平衡二叉树
//两个递归函数，一个计算树的高度，一个判断是否平衡
class Solution {
public:
  int height(TreeNode *root) {
    if (!root)
      return 0;
    return max(height(root->left), height(root->right)) + 1;
  }
  bool isBalanced(TreeNode *root) {
    if (!root)
      return true;
    return isBalanced(root->left) && isBalanced(root->right) &&
           abs(height(root->left) - height(root->right)) <= 1;
  }
};
// @lc code=end

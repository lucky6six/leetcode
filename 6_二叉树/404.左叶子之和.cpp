/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 *
 * https://leetcode.cn/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (62.77%)
 * Likes:    708
 * Dislikes: 0
 * Total Accepted:    299.9K
 * Total Submissions: 477.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定二叉树的根节点 root ，返回所有左叶子之和。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入: root = [3,9,20,null,null,15,7]
 * 输出: 24
 * 解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 *
 *
 * 示例 2:
 *
 *
 * 输入: root = [1]
 * 输出: 0
 *
 *
 *
 *
 * 提示:
 *
 *
 * 节点数在 [1, 1000] 范围内
 * -1000 <= Node.val <= 1000
 *
 *
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;
//二叉树节点
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}      //构造函数
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} //构造函数
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {} //构造函数
};
// @lc code=start
//直接想到递归子树求和
class Solution {
public:
  int sumOfLeftLeaves(TreeNode *root) {
    //终止条件为root为空
    if (root == nullptr)
      return 0;
    //加一个判空条件，防止下一条语句访问空指针
    if (root->left == nullptr)
      return sumOfLeftLeaves(root->right);
    //找到左叶子节点
    if (root->left->left == nullptr && root->left->right == nullptr)
      return root->left->val + sumOfLeftLeaves(root->right);
    //正常递归子树
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
  }
};
// @lc code=end

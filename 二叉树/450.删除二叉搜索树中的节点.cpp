/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 *
 * https://leetcode.cn/problems/delete-node-in-a-bst/description/
 *
 * algorithms
 * Medium (52.30%)
 * Likes:    1330
 * Dislikes: 0
 * Total Accepted:    260.8K
 * Total Submissions: 498.8K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n3'
 *
 * 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key
 * 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
 *
 * 一般来说，删除节点可分为两个步骤：
 *
 *
 * 首先找到需要删除的节点；
 * 如果找到了，删除它。
 *
 *
 *
 *
 * 示例 1:
 *
 *
 *
 *
 * 输入：root = [5,3,6,2,4,null,7], key = 3
 * 输出：[5,4,6,2,null,null,7]
 * 解释：给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
 * 一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
 * 另一个正确答案是 [5,2,6,null,4,null,7]。
 *
 *
 *
 *
 * 示例 2:
 *
 *
 * 输入: root = [5,3,6,2,4,null,7], key = 0
 * 输出: [5,3,6,2,4,null,7]
 * 解释: 二叉树不包含值为 0 的节点
 *
 *
 * 示例 3:
 *
 *
 * 输入: root = [], key = 0
 * 输出: []
 *
 *
 *
 * 提示:
 *
 *
 * 节点数的范围 [0, 10^4].
 * -10^5 <= Node.val <= 10^5
 * 节点值唯一
 * root 是合法的二叉搜索树
 * -10^5 <= key <= 10^5
 *
 *
 *
 *
 * 进阶： 要求算法时间复杂度为 O(h)，h 为树的高度。
 *
 */
//删除操作真的要考虑重构二叉树了，开旋！
#include <iostream>

using namespace std;
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

//法一，替换法
//类似插入，如果删除点不在叶子，找其右子树最小点替换，然后删除右子树最小点
//或找左子树最大点替换，然后删除左子树最大点
class Solution {
public:
  int getMinValue(TreeNode *root) {
    while (root->left != nullptr)
      root = root->left;
    return root->val;
  }
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr)
      return nullptr;
    if (root->val == key) {
      if (root->left == nullptr)
        return root->right;
      if (root->right == nullptr)
        return root->left;
      int tmp = getMinValue(root->right);
      root->right = deleteNode(root->right, tmp);
      root->val = tmp;
    } else if (root->val > key) {
      root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
      root->right = deleteNode(root->right, key);
    }
    return root;
  }
};
// @lc code=start

//法二，旋转法
class Solution {
  TreeNode *pre;

public:
  TreeNode *getMinValueNode(TreeNode *root) {
    while (root->left != nullptr)
      root = root->left;
    return root;
  }
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr)
      return nullptr;
    //先找删除点
    if (root->val == key) {
      //有一边子树为空，另一边补上，都为空返回nullptr
      if (root->left == nullptr)
        return root->right;
      if (root->right == nullptr)
        return root->left;
      //两边子树都存在
      //将左子树挂在右子树最小点的左边，返回右子树的根节点
      TreeNode *tmp = getMinValueNode(root->right);
      tmp->left = root->left;
      return root->right;
    } else if (root->val > key) {
      root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
      root->right = deleteNode(root->right, key);
    }
    return root;
  }
};
// @lc code=end

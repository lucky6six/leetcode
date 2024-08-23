/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode.cn/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (60.06%)
 * Likes:    2700
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,2,3,4,4,3]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,2,null,3,null,3]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [1, 1000] 内
 * -100 <= Node.val <= 100
 *
 *
 *
 *
 * 进阶：你可以运用递归和迭代两种方法解决这个问题吗？
 *
 */

#include <stack>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

//直观思路，递归，判断左右子树是否对称
class Solution {
public:
  bool isMirror(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr) {
      return true;
    }
    //先判断nullptr，再判断val
    if (left == nullptr || right == nullptr) {
      return false;
    }
    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left) && left->val == right->val;
  }
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    return isMirror(root->right, root->left);
  }
};

//思路，翻转树，判断前后是否相同.这里不能直接判断，因为翻转后的树会改变原树！！！！需要先clone一份
class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr)
      return nullptr;
    //这其实也是一种遍历的思想，只是这里是后序遍历
    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
  }
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
      return true;
    }
    if (p == nullptr || q == nullptr) {
      return false;
    }
    if (p->val != q->val) {
      return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
  bool isSymmetric(TreeNode *root) {
    //翻转树
    //这里不能直接判断，因为翻转后的树会改变原树！！！！需要先clone一份
    //如果想要in-place,可以只翻转左子树，然后判断左右子树是否相同
    invertTree(root->left);
    return isSameTree(root->left, root->right);
  };
};

// @lc code=start
//另一个思路，迭代，使用栈//队列
//原理和递归一样，只是用栈模拟递归
class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    stack<TreeNode *> s;
    s.push(root->left);
    s.push(root->right);
    while (!s.empty()) {
      TreeNode *right = s.top();
      s.pop();
      TreeNode *left = s.top();
      s.pop();
      if (left == nullptr && right == nullptr) {
        continue;
      }
      if (left == nullptr || right == nullptr) {
        return false;
      }
      if (left->val != right->val) {
        return false;
      }
      s.push(left->left);
      s.push(right->right);
      s.push(left->right);
      s.push(right->left);
    }
    return true;
  }
};

// @lc code=end

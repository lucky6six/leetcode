/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode.cn/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (76.59%)
 * Likes:    1172
 * Dislikes: 0
 * Total Accepted:    769.5K
 * Total Submissions: 1M
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,null,2,3]
 * 输出：[3,2,1]
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
 * 输入：root = [1]
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [0, 100] 内
 * -100 <= Node.val <= 100
 *
 *
 *
 *
 * 进阶：递归算法很简单，你可以通过迭代算法完成吗？
 *
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

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

class Solution {
public:
  vector<int> postorder(TreeNode *root, vector<int> &res) {
    if (root == nullptr)
      return res;
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
    return res;
  }

  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    return postorder(root, res);
  }
};
// @lc code=start

class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    //注意栈中存放的是指针
    stack<TreeNode *> stk;
    if (root == nullptr) {
      return res;
    }
    stk.push(root);
    while (!stk.empty()) {
      TreeNode *node = stk.top();
      stk.pop();
      //巧妙借用前序遍历的思想，只不过是先左后右，最后反转
      //得到中右左的遍历结果，再反转得到左右中的遍历结果
      res.push_back(node->val);
      if (node->left != nullptr)
        stk.push(node->left);
      if (node->right != nullptr)
        stk.push(node->right);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

// @lc code=end

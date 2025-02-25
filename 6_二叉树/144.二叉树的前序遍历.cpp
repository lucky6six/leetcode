/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (71.81%)
 * Likes:    1245
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,null,2,3]
 * 输出：[1,2,3]
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
 * 示例 4：
 *
 *
 * 输入：root = [1,2]
 * 输出：[1,2]
 *
 *
 * 示例 5：
 *
 *
 * 输入：root = [1,null,2]
 * 输出：[1,2]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [0, 100] 内
 * -100
 *
 *
 *
 *
 * 进阶：递归算法很简单，你可以通过迭代算法完成吗？
 *
 */
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

//递归解法
class Solution {
public:
  //递归三步走
  // 1.确定递归函数的参数和返回值
  vector<int> preorder(TreeNode *root, vector<int> res) {
    // 2.确定终止条件
    if (root == nullptr) {
      return res;
    }
    // 3.确定单层递归逻辑
    res.push_back(root->val);
    res = preorder(root->left, res);
    res = preorder(root->right, res);
    return res;
  }

  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    return preorder(root, res);
  }
};
// @lc code=start

//迭代解法
class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    if (root == nullptr) {
      return res;
    }
    //注意这里要存放指针
    stack<TreeNode *> stk;
    //用栈模拟递归，入栈顺序是右节点，左节点，因为出栈顺序是左节点，右节点
    stk.push(root);
    while (!stk.empty()) {
      TreeNode *node = stk.top();
      stk.pop();
      res.push_back(node->val);
      //弹出根节点后，先将右节点入栈，再将左节点入栈
      if (node->right != nullptr) {
        stk.push(node->right);
      }
      if (node->left != nullptr) {
        stk.push(node->left);
      }
    }

    return res;
  }
};
// @lc code=end

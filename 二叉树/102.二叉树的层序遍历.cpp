/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (67.07%)
 * Likes:    1949
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 1.5M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。
 * （即逐层地，从左到右访问所有节点）。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[9,20],[15,7]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1]
 * 输出：[[1]]
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [0, 2000] 内
 * -1000 <= Node.val <= 1000
 *
 *
 */
#include <queue>
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

//迭代
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    queue<pair<TreeNode *, int>> q;
    vector<vector<int>> res;
    if (!root) {
      return res;
    }
    q.emplace(root, 0);
    while (!q.empty()) {
      auto [node, level] = q.front();
      //二维数组res的size等于当前层数，说明当前层还没有元素
      //二维vector的size()方法返回的是行数，新行需要先手动创建
      if (res.size() == level) {
        res.push_back({});
      }
      res[level].push_back(node->val);
      if (node->left) {
        q.emplace(node->left, level + 1);
      }
      if (node->right) {
        q.emplace(node->right, level + 1);
      }
      q.pop();
    }
    return res;
  }
};
// @lc code=start

//递归
//回顾迭代，每次需要传递当前节点和层数
//这种其实是深搜，类似于前序遍历，只是加了一个层数，每次遍历到新的层数，就新建一个vector，最后同一层序返回
class Solution {
public:
  vector<vector<int>> Order(TreeNode *root, vector<vector<int>> &res,
                            int level) {
    if (res.size() == level) {
      res.push_back({});
    }
    //因为返回的是二维数组，实际上不用介意根节点和子节点的顺序，只要保证同一层的节点先左后右顺序即可
    res[level].push_back(root->val);
    if (root->left) {
      Order(root->left, res, level + 1);
    }
    if (root->right) {
      Order(root->right, res, level + 1);
    }
    //即可以先遍历完左右子树在加入根节点
    // res[level].push_back(root->val);
    return res;
  }
  vector<vector<int>> levelOrder(TreeNode *root) {

    vector<vector<int>> res;
    if (!root) {
      return res;
    }
    Order(root, res, 0);
    return res;
  }
};

// @lc code=end

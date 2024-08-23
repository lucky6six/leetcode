/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 *
 * https://leetcode.cn/problems/average-of-levels-in-binary-tree/description/
 *
 * algorithms
 * Easy (70.44%)
 * Likes:    484
 * Dislikes: 0
 * Total Accepted:    191.6K
 * Total Submissions: 271.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个非空二叉树的根节点 root ,
 * 以数组的形式返回每一层节点的平均值。与实际答案相差 10^-5
 * 以内的答案可以被接受。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[3.00000,14.50000,11.00000]
 * 解释：第 0 层的平均值为 3,第 1 层的平均值为 14.5,第 2 层的平均值为 11 。
 * 因此返回 [3, 14.5, 11] 。
 *
 *
 * 示例 2:
 *
 *
 *
 *
 * 输入：root = [3,9,20,15,7]
 * 输出：[3.00000,14.50000,11.00000]
 *
 *
 *
 *
 * 提示：
 *
 *
 *
 *
 * 树中节点数量在 [1, 10^4] 范围内
 * -2^31 <= Node.val <= 2^31 - 1
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

class Solution {
public:
  vector<double> averageOfLevels(TreeNode *root) {
    queue<pair<TreeNode *, int>> q;
    vector<vector<int>> res;
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
    //层序遍历结束后，计算每一层的平均值
    vector<double> ans;
    //使用引用可以减少copy
    for (auto &v : res) {
      double sum = 0;
      for (auto &i : v) {
        sum += i;
      }
      ans.push_back(sum / v.size());
    }

    return ans;
  }
};

// @lc code=start
//然而用迭代法层序遍历实际上并不一定要添加level参数，可以每层统计节点个数即可。
class Solution {
public:
  vector<double> averageOfLevels(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    vector<double> ans;
    while (!q.empty()) {
      //每层遍历前先确定大小，下个循环时前一个层节点已经出列，当前层节点已经全部入列
      int n = q.size();
      double sum = 0;
      for (int i = 0; i < n; i++) {
        TreeNode *node = q.front();
        q.pop();
        sum += node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      ans.push_back(sum / n);
    }
    return ans;
  }
};
// @lc code=end

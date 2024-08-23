/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 *
 * https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (73.58%)
 * Likes:    458
 * Dislikes: 0
 * Total Accepted:    200.6K
 * Total Submissions: 272.6K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * 给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
 *
 * 树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：root = [1,null,3,2,4,null,5,6]
 * 输出：[[1],[3,2,4],[5,6]]
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * 输出：[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树的高度不会超过 1000
 * 树的节点总数在 [0, 10^4] 之间
 *
 *
 */
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

// @lc code=start

class Solution {
public:
  //和二叉树遍历类似，只是要增加一个循环，遍历每个子节点
  vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> res;
    if (root == nullptr) {
      return res;
    }
    queue<Node *> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
      int size = q.size();
      res.push_back({});
      for (int i = 0; i < size; i++) {
        Node *node = q.front();
        q.pop();
        res[level].push_back(node->val);
        for (auto child : node->children) {
          q.push(child);
        }
      }
      level++;
    }
    return res;
  }
};
// @lc code=end

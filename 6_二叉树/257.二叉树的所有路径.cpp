/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode.cn/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (70.69%)
 * Likes:    1129
 * Dislikes: 0
 * Total Accepted:    389.7K
 * Total Submissions: 551.2K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给你一个二叉树的根节点 root ，按 任意顺序
 * ，返回所有从根节点到叶子节点的路径。
 *
 * 叶子节点 是指没有子节点的节点。
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,3,null,5]
 * 输出：["1->2->5","1->3"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1]
 * 输出：["1"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [1, 100] 内
 * -100 <= Node.val <= 100
 *
 *
 */

#include <iostream>
#include <stack>
#include <string>
#include <vector>

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

//用栈迭代的写法，我们可以发现树的题目基本上都基于遍历的骨架
class Solution {
public:
  vector<string> binaryTreePaths(TreeNode *root) {
    stack<TreeNode *> treeSt; // 保存树的遍历节点
    stack<string> pathSt;     // 保存遍历路径的节点
    vector<string> result;    // 保存最终路径集合
    if (root == NULL)
      return result;
    treeSt.push(root);
    pathSt.push(to_string(root->val));
    while (!treeSt.empty()) {
      TreeNode *node = treeSt.top();
      treeSt.pop(); // 取出节点 中
      string path = pathSt.top();
      pathSt.pop(); // 取出该节点对应的路径
      if (node->left == NULL && node->right == NULL) { // 遇到叶子节点
        result.push_back(path);
      }
      if (node->right) { // 右
        treeSt.push(node->right);
        pathSt.push(path + "->" + to_string(node->right->val));
      }
      if (node->left) { // 左
        treeSt.push(node->left);
        pathSt.push(path + "->" + to_string(node->left->val));
      }
    }
    return result;
  }
};
// @lc code=start

class Solution {
  vector<string> res;

public:
  void dfs(TreeNode *root, string path) {
    if (!root)
      return;
    path += to_string(root->val);
    if (!root->left && !root->right) {
      //这里其实包含了一种回溯在里面，没次有一个路径push，就
      //跟了一个return，由于是值传递，所以不用回溯（调用栈回溯），也丢掉了后续的路径
      res.push_back(path);
      return;
    }
    path += "->";
    dfs(root->left, path);
    dfs(root->right, path);
    return;
  }
  //递归遍历，不过要注意的是，这里的path是值传递，所以不用回溯
  //终止条件要做出修改，不是root==nullptr，而是root->left==nullptr&&root->right==nullptr
  //即发现叶子节点，将当前路径加入结果集
  //当nullptr的上级不是叶子节点时，不会将当前路径加入结果集，直接return。
  vector<string> binaryTreePaths(TreeNode *root) {
    if (!root) {
      return res;
    }
    dfs(root, "");
    return res;
  }
};

// @lc code=end

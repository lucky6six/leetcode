/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode.cn/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Easy (76.71%)
 * Likes:    2069
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,null,2,3]
 * 输出：[1,3,2]
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
 * 树中节点数目在范围 [0, 100] 内
 * -100 <= Node.val <= 100
 *
 *
 *
 *
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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

class Solution {
public:
  //注意引用传递res
  vector<int> inorder(TreeNode *root, vector<int> &res) {
    if (root == nullptr) {
      return res;
    }
    //左中右
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
    return res;
  }
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    return inorder(root, res);
  }
};
// @lc code=start

class Solution {
public:
  //迭代解法,无法像中序遍历一样在弹出根节点的同时访问根节点，因为要先访问左子树
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    if (root == nullptr)
      return res;
    stack<TreeNode *> stk;
    //不能只依赖栈，要有指针指向当前节点
    TreeNode *cur = root;
    //利用栈遍历数据结构时记得原则，后入栈的先遍历。
    while (!stk.empty() || cur != nullptr) {
      if (cur != nullptr) {
        //左子树逐层入栈
        stk.push(cur);
        cur = cur->left;
        //直至左子树为空
      } else {
        //左子树遍历完毕，访问根节点
        cur = stk.top();
        stk.pop();
        //根节点入结果数组
        res.push_back(cur->val);
        //根节点访问完，访问右子树
        cur = cur->right;
      }
    }

    return res;
  }
};

// @lc code=end

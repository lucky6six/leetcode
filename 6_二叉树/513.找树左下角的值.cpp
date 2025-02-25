/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 *
 * https://leetcode.cn/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (73.21%)
 * Likes:    574
 * Dislikes: 0
 * Total Accepted:    243.8K
 * Total Submissions: 333.1K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
 *
 * 假设二叉树中至少有一个节点。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 *
 * 输入: root = [2,1,3]
 * 输出: 1
 *
 *
 * 示例 2:
 *
 * ⁠
 *
 *
 * 输入: [1,2,3,4,null,5,6,null,null,7]
 * 输出: 7
 *
 *
 *
 *
 * 提示:
 *
 *
 * 二叉树的节点个数的范围是 [1,10^4]
 * -2^31  
 *
 *
 */
#include <queue>
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
//直观:层序遍历,每层第一个节点即为最左边的节点，最后一层的第一个节点即为最底层最左边的节点
//时间复杂度O(n),空间复杂度O(n)，因为树不规则，所以至少要遍历，所以时间复杂度最低为O(n)
class Solution {
public:
  int findBottomLeftValue(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int left = root->val;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode *node = q.front();
        q.pop();
        if (i == 0)
          left = node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
    }
    return left;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 *
 * https://leetcode.cn/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (62.80%)
 * Likes:    555
 * Dislikes: 0
 * Total Accepted:    243K
 * Total Submissions: 387K
 * Testcase Example:  '[4,2,6,1,3]'
 *
 * 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
 *
 * 差值是一个正数，其数值等于两值之差的绝对值。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [4,2,6,1,3]
 * 输出：1
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,0,48,null,null,12,49]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目范围是 [2, 10^4]
 * 0 <= Node.val <= 10^5
 *
 *
 *
 *
 * 注意：本题与 783
 * https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ 相同
 *
 */

//二叉树节点
#include <algorithm>
#include <iostream>

using namespace std;
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
//直观思路：bst中序遍历转换为有序数组，遍历得值
//优化：中序遍历的过程中直接计算最小差值，需要记录前一个结点的值
//初始化过程中的一些细节要注意
class Solution {
  int result, pre;

public:
  void dfs(TreeNode *root) {
    if (root == nullptr)
      return;
    //中序遍历
    dfs(root->left);
    if (root->val != pre)
      result = min(result, abs(root->val - pre));

    pre = root->val;
    dfs(root->right);
  }
  int getMinimumDifference(TreeNode *root) {
    if (root->left == nullptr)
      result = abs(root->val - root->right->val);
    else
      result = abs(root->val - root->left->val);
    pre = root->val;
    dfs(root);
    return result;
  }
};
// @lc code=end

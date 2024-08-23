/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 *
 * https://leetcode.cn/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Easy (81.54%)
 * Likes:    1123
 * Dislikes: 0
 * Total Accepted:    385.9K
 * Total Submissions: 473.1K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
 *
 * 完全二叉树
 * 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第
 * h 层，则该层包含 1~ 2^h 个节点。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,3,4,5,6]
 * 输出：6
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = []
 * 输出：0
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [1]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目范围是[0, 5 * 10^4]
 * 0
 * 题目数据保证输入的树是 完全二叉树
 *
 *
 *
 *
 * 进阶：遍历树来统计节点是一种时间复杂度为 O(n)
 * 的简单解决方案。你可以设计一个更快的算法吗？
 *
 */

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

class Solution {
public:
  int countNodes(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int left = countNodes(root->left);
    int right = countNodes(root->right);
    return left + right + 1;
  }
};
// @lc code=start

//进阶：遍历树来统计节点是一种时间复杂度为 O(n)
//的简单解决方案。你可以设计一个更快的算法吗？

//直观，利用完全二叉性质，跳过前n层，然后二分查找最后一层
//卡住：如何判断最后一层的节点是否存在，若要遍历查找，需要从上层开始，又回到遍历
// hint：左子树一定是满二叉树，右子树可能是满二叉树，O( logN logN )
class Solution {
public:
  int countNodes(TreeNode *root) {
    if (root == nullptr)
      return 0;
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    int leftDepth = 0,
        rightDepth = 0; // 这里初始为0是有目的的，为了下面求指数方便
    while (left) { // 求左子树深度
      left = left->left;
      leftDepth++;
    }
    while (right) { // 求右子树深度
      right = right->right;
      rightDepth++;
    }
    //左子树深度等于右子树深度，由于完全二叉树，实际发现满二叉树
    if (leftDepth == rightDepth) {
      return (2 << leftDepth) - 1; // 注意(2<<1) 相当于2^2，所以leftDepth初始为0
    }
    //仍是递归，但递归的终止条件增加，即当发现左子树深度等于右子树深度时，即发现满二叉树时，直接返回数量
    return countNodes(root->left) + countNodes(root->right) + 1;
  }
};
// @lc code=end

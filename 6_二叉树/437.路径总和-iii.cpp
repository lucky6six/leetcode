/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 *
 * https://leetcode.cn/problems/path-sum-iii/description/
 *
 * algorithms
 * Medium (47.58%)
 * Likes:    2004
 * Dislikes: 0
 * Total Accepted:    392.3K
 * Total Submissions: 824.5K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * 给定一个二叉树的根节点 root ，和一个整数 targetSum
 * ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
 *
 * 路径
 * 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
 * 输出：3
 * 解释：和等于 8 的路径有 3 条，如图所示。
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * 输出：3
 *
 *
 *
 *
 * 提示:
 *
 *
 * 二叉树的节点个数的范围是 [0,1000]
 * -10^9  
 * -1000  
 *
 *
 */

#include <unordered_map>
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

// dfs,访问到每个节点时，利用前缀和集合得到以该节点为末端的路径数目，并统计！(每次不一定只有一条，用map)
//  @lc code=start

class Solution {
public:
  // 前缀和及其数量
  unordered_map<long long, int> map;
  long sum = 0;
  int ret = 0;
  void dfs(TreeNode *root, long targetSum) {
    if (root == nullptr)
      return;
    sum += root->val;
    if (map.find(sum - targetSum) != map.end())
      ret += map[sum - targetSum];
    map[sum]++;
    dfs(root->left, targetSum);
    dfs(root->right, targetSum);
    // 回溯要彻底
    map[sum]--;
    sum -= root->val;
  }
  int pathSum(TreeNode *root, long targetSum) {
    // 前缀和有一个0位的值，可以从根节点开算
    map[0] = 1;
    dfs(root, targetSum);
    return ret;
  }
};
// @lc code=end

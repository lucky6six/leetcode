/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (78.32%)
 * Likes:    1504
 * Dislikes: 0
 * Total Accepted:    468.4K
 * Total Submissions: 597.6K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 平衡
 * 二叉搜索树。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-10,-3,0,5,9]
 * 输出：[0,-3,9,-10,null,5]
 * 解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,3]
 * 输出：[3,1]
 * 解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums 按 严格递增 顺序排列
 *
 *
 */

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

// @lc code=start

//我的想法，要求平衡，每次取数组中间值作为根节点，左右子树为左右数组，递归调用本函数
//来写个左闭右闭吧
class Solution {
public:
  TreeNode *buildTree(vector<int> &nums, int left, int right) {
    if (left > right)
      return nullptr;
    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = buildTree(nums, left, mid - 1);
    root->right = buildTree(nums, mid + 1, right);
    return root;
  }
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return buildTree(nums, 0, nums.size() - 1);
  }
};
// @lc code=end

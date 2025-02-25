/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 *
 * https://leetcode.cn/problems/maximum-binary-tree/description/
 *
 * algorithms
 * Medium (82.12%)
 * Likes:    775
 * Dislikes: 0
 * Total Accepted:    248.3K
 * Total Submissions: 302.4K
 * Testcase Example:  '[3,2,1,6,0,5]'
 *
 * 给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums
 * 递归地构建:
 *
 *
 * 创建一个根节点，其值为 nums 中的最大值。
 * 递归地在最大值 左边 的 子数组前缀上 构建左子树。
 * 递归地在最大值 右边 的 子数组后缀上 构建右子树。
 *
 *
 * 返回 nums 构建的 最大二叉树 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [3,2,1,6,0,5]
 * 输出：[6,3,5,null,2,0,null,null,1]
 * 解释：递归调用如下所示：
 * - [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
 * ⁠   - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是
 * [2,1] 。 ⁠       - 空数组，无子节点。 ⁠       - [2,1]
 * 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。 ⁠ -
 * 空数组，无子节点。 ⁠           -
 * 只有一个元素，所以子节点是一个值为 1 的节点。
 * ⁠   - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是
 * [] 。 ⁠       - 只有一个元素，所以子节点是一个值为 0
 * 的节点。 ⁠       - 空数组，无子节点。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [3,2,1]
 * 输出：[3,null,2,null,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 1000
 * nums 中的所有整数 互不相同
 *
 *
 */
#include <vector>

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

class Solution {
public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    if (nums.empty())
      return nullptr;
    int max_index = 0;
    int max = nums[0];
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > max) {
        max = nums[i];
        max_index = i;
      }
    }
    TreeNode *root = new TreeNode(max);
    //快捷构造vector
    vector<int> left(nums.begin(), nums.begin() + max_index);
    vector<int> right(nums.begin() + max_index + 1, nums.end());
    root->left = constructMaximumBinaryTree(left);
    root->right = constructMaximumBinaryTree(right);
    return root;
  }
};

//构造vector可能很慢，可以使用下面的方法，传递nums与索引
// @lc code=start
class Solution {
public:
  TreeNode *build(vector<int> &nums, int l, int r) {
    //左闭右开，等于也是无取值
    if (l >= r)
      return nullptr;
    int max_index = l;
    for (int i = l + 1; i < r; i++) {
      if (nums[i] > nums[max_index]) {
        max_index = i;
      }
    }
    TreeNode *root = new TreeNode(nums[max_index]);
    root->left = build(nums, l, max_index);
    root->right = build(nums, max_index + 1, r);
    return root;
  }
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    if (nums.empty())
      return nullptr;
    //左闭右开
    return build(nums, 0, nums.size());
  }
};
// @lc code=end

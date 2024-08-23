/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode.cn/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (37.79%)
 * Likes:    2322
 * Dislikes: 0
 * Total Accepted:    898.9K
 * Total Submissions: 2.4M
 * Testcase Example:  '[2,1,3]'
 *
 * 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
 *
 * 有效 二叉搜索树定义如下：
 *
 *
 * 节点的左子树只包含 小于 当前节点的数。
 * 节点的右子树只包含 大于 当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [2,1,3]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [5,1,4,null,null,3,6]
 * 输出：false
 * 解释：根节点的值是 5 ，但是右子节点的值是 4 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目范围在[1, 10^4] 内
 * -2^31 <= Node.val <= 2^31 - 1
 *
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

//错误解法
//只考虑到每层递归，比较root及其左右子根
//未考虑到整个树的结构，即左子树的所有节点都小于root，右子树的所有节点都大于root
class Solution {
public:
  bool isValidBST(TreeNode *root) {
    if (root == nullptr)
      return true;
    if (root->left == nullptr && root->right == nullptr)
      return true;
    if (root->left == nullptr && root->right != nullptr) {
      if (root->val < root->right->val) {
        return isValidBST(root->right);
      } else {
        return false;
      }
    }
    if (root->left != nullptr && root->right == nullptr) {
      if (root->val > root->left->val) {
        return isValidBST(root->left);
      } else {
        return false;
      }
    }
    return isValidBST(root->left) && isValidBST(root->right);
  }
};

// @lc code=start
//所以在递归时要保留的不仅仅是最近的父节点，更要考虑到祖先节点信息
//即在递归时，传递上下界信息

//该头文件记录了long long的最大最小值
#include <climits>

using namespace std;

class Solution {
public:
  bool isValidBST(TreeNode *root, long long lower, long long upper) {
    if (root == nullptr)
      return true;
    if (root->val <= lower || root->val >= upper)
      return false;
    return isValidBST(root->left, lower, root->val) &&
           isValidBST(root->right, root->val, upper);
  }
  bool isValidBST(TreeNode *root) {
    return isValidBST(root, LONG_MIN, LONG_MAX);
  }
};
// summary 二叉搜索树bst的本质上是对取值空间的不断划分！

//法二：中序遍历
// bst中序遍历得到的结果是递增的
// @lc code=end

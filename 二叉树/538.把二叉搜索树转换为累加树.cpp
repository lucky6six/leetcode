/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 *
 * https://leetcode.cn/problems/convert-bst-to-greater-tree/description/
 *
 * algorithms
 * Medium (77.30%)
 * Likes:    994
 * Dislikes: 0
 * Total Accepted:    277.1K
 * Total Submissions: 358.4K
 * Testcase Example:  '[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]'
 *
 * 给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater
 * Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。
 *
 * 提醒一下，二叉搜索树满足下列约束条件：
 *
 *
 * 节点的左子树仅包含键 小于 节点键的节点。
 * 节点的右子树仅包含键 大于 节点键的节点。
 * 左右子树也必须是二叉搜索树。
 *
 *
 * 注意：本题和 1038:
 * https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/
 * 相同
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
 * 输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
 *
 *
 * 示例 2：
 *
 * 输入：root = [0,null,1]
 * 输出：[1,null,1]
 *
 *
 * 示例 3：
 *
 * 输入：root = [1,0,2]
 * 输出：[3,3,2]
 *
 *
 * 示例 4：
 *
 * 输入：root = [3,2,4,1]
 * 输出：[7,9,4,10]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中的节点数介于 0 和 10^4^ 之间。
 * 每个节点的值介于 -10^4 和 10^4 之间。
 * 树中的所有值 互不相同 。
 * 给定的树为二叉搜索树。
 *
 *
 */
#include <iostream>

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
//我的思路：先令所有节点获得右子树的值（后序，递归），再令所有左节点获得父节点的值（前序，递归）。

//正经的思路：bst有序性，中序，但此时是从大到小，反中序，即右中左，实际上就是中序遍历里面左右子树顺序变一下。
class Solution {
public:
  //递归回来的时候不希望回溯sum（需要子树和），引用传递
  int revalue(TreeNode *root, int &sum) {
    if (root == nullptr) {
      return 0;
    }
    revalue(root->right, sum);
    //此时正好按从大到小执行该步骤
    sum += root->val;
    root->val = sum;
    revalue(root->left, sum);
    return 0;
  }
  TreeNode *convertBST(TreeNode *root) {
    int sum = 0;
    revalue(root, sum);
    return root;
  }
};
// @lc code=end

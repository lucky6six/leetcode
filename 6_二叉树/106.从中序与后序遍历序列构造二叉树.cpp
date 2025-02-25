/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (72.22%)
 * Likes:    1213
 * Dislikes: 0
 * Total Accepted:    376.9K
 * Total Submissions: 522.1K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历，
 * postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * 输出：[3,9,20,null,null,15,7]
 *
 *
 * 示例 2:
 *
 *
 * 输入：inorder = [-1], postorder = [-1]
 * 输出：[-1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= inorder.length <= 3000
 * postorder.length == inorder.length
 * -3000 <= inorder[i], postorder[i] <= 3000
 * inorder 和 postorder 都由 不同 的值组成
 * postorder 中每一个值都在 inorder 中
 * inorder 保证是树的中序遍历
 * postorder 保证是树的后序遍历
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
//注意类似用数组构造二叉树的题目，每次分隔尽量不要定义新的数组，而是通过下标索引直接在原数组上操作，这样可以节约时间和空间上的开销。
// @lc code=start
class Solution {
public:
  TreeNode *build(vector<int> &inorder, vector<int> &postorder, int in_left,
                  int in_right, int post_left, int post_right) {
    if (in_left > in_right)
      return nullptr;
    if (in_left == in_right)
      return new TreeNode(inorder[in_left]);
    int root_val = postorder[post_right];
    TreeNode *root = new TreeNode(root_val);
    for (int i = in_left; i <= in_right; i++) {
      if (inorder[i] == root_val) {
        // 最后一个参数post_left + ((i-1) - in_left) 加中序左侧长度
        root->left = build(inorder, postorder, in_left, i - 1, post_left,
                           post_left + i - in_left - 1);
        // 第五个参数跟着上一行最后一个参数后面
        root->right = build(inorder, postorder, i + 1, in_right,
                            post_left + i - in_left, post_right - 1);
        break;
      }
    }
    return root;
  }
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    //左闭右闭写法，为了减少新建vector的开销，传递索引
    return build(inorder, postorder, 0, inorder.size() - 1, 0,
                 postorder.size() - 1);
  }
};
// @lc code=end

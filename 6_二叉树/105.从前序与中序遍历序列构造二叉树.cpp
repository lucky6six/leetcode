/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (71.56%)
 * Likes:    2284
 * Dislikes: 0
 * Total Accepted:    639.4K
 * Total Submissions: 893.2K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历，
 * inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * 输出: [3,9,20,null,null,15,7]
 *
 *
 * 示例 2:
 *
 *
 * 输入: preorder = [-1], inorder = [-1]
 * 输出: [-1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder 和 inorder 均 无重复 元素
 * inorder 均出现在 preorder
 * preorder 保证 为二叉树的前序遍历序列
 * inorder 保证 为二叉树的中序遍历序列
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
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
// @lc code=start
class Solution {
public:
  TreeNode *build(vector<int> &preorder, int preStart, int preEnd,
                  vector<int> &inorder, int inStart, int inEnd) {
    if (preStart > preEnd) {
      return nullptr;
    }
    if (preStart == preEnd) {
      return new TreeNode(preorder[preStart]);
    }
    auto root = new TreeNode(preorder[preStart]);
    int rootIndex = inStart;
    while (inorder[rootIndex] != preorder[preStart]) {
      rootIndex++;
    }
    root->left = build(preorder, preStart + 1, preStart + rootIndex - inStart,
                       inorder, inStart, rootIndex - 1);
    root->right = build(preorder, preStart + rootIndex - inStart + 1, preEnd,
                        inorder, rootIndex + 1, inEnd);
    return root;
  }
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    //左闭右闭
    return build(preorder, 0, preorder.size() - 1, inorder, 0,
                 inorder.size() - 1);
  }
};
// @lc code=end

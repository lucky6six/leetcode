/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 *
 * https://leetcode.cn/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (55.14%)
 * Likes:    746
 * Dislikes: 0
 * Total Accepted:    205.2K
 * Total Submissions: 371.9K
 * Testcase Example:  '[1,null,2,2]'
 *
 * 给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有
 * 众数（即，出现频率最高的元素）。
 *
 * 如果树中有不止一个众数，可以按 任意顺序 返回。
 *
 * 假定 BST 满足如下定义：
 *
 *
 * 结点左子树中所含节点的值 小于等于 当前节点的值
 * 结点右子树中所含节点的值 大于等于 当前节点的值
 * 左子树和右子树都是二叉搜索树
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,null,2,2]
 * 输出：[2]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [0]
 * 输出：[0]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [1, 10^4] 内
 * -10^5 <= Node.val <= 10^5
 *
 *
 *
 *
 * 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
 *
 */

//二叉树节点
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
//与503一样，中序遍历，找到众数
class Solution {
  //众数计数
  int maxCount = 1;
  //当前计数
  int count = 0;
  //前一个节点
  int val = 10001;
  //结果集
  vector<int> result;

public:
  void inorder(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    inorder(root->left);
    //相同，计数+1，等于max，加入结果集，大于max，清空结果集再加入结果集
    if (root->val == val) {
      count++;
      //不同，计数重置为1，更新val
    } else {
      if (count == maxCount) {
        result.push_back(val);
      } else if (count > maxCount) {
        result.clear();
        result.push_back(val);
        maxCount = count;
      }
      count = 1;
      val = root->val;
    }
    inorder(root->right);
    return;
  }
  vector<int> findMode(TreeNode *root) {
    //中序遍历
    inorder(root);
    //这是为了处理最后一个val
    //这种方法不会产生先push，再清空，再push的循环，只在val值改变时进行操作
    if (count == maxCount) {
      result.push_back(val);
    } else if (count > maxCount) {
      result.clear();
      result.push_back(val);
      maxCount = count;
    }
    return result;
  }
};
// @lc code=end

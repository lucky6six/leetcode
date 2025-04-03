/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 *
 * https://leetcode.cn/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (69.47%)
 * Likes:    1173
 * Dislikes: 0
 * Total Accepted:    555K
 * Total Submissions: 798.4K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * 给定一个二叉树的 根节点
 * root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,3,null,5,null,4]
 *
 * 输出：[1,3,4]
 *
 * 解释：
 *
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,3,4,null,null,null,5]
 *
 * 输出：[1,3,4,5]
 *
 * 解释：
 *
 *
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [1,null,3]
 *
 * 输出：[1,3]
 *
 *
 * 示例 4：
 *
 *
 * 输入：root = []
 *
 * 输出：[]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 二叉树的节点个数的范围是 [0,100]
 * -100 <= Node.val <= 100 
 *
 *
 */
#include <queue>
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
// 实际上是层序遍历每一层的最后值,由于只需要最后一个值，节省空间，不需要全部存储，只需要一个flag记录层级和前一个节点，当层级改变时推入前一个节点值。
//  @lc code=start

class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    queue<pair<TreeNode *, int>> q;
    vector<int> ret;
    int level = 0;
    TreeNode *prev = root;
    if (!root) {
      return ret;
    }
    q.emplace(root, 0);
    while (!q.empty()) {
      TreeNode *tmp;
      int now_level;
      tmp = q.front().first;
      now_level = q.front().second;
      if (now_level > level) {
        ret.push_back(prev->val);
        level++;
      }
      q.pop();
      prev = tmp;
      if (tmp->left)
        q.emplace(tmp->left, now_level + 1);
      if (tmp->right)
        q.emplace(tmp->right, now_level + 1);
    }
    ret.push_back(prev->val);
    return ret;
  }
};
// @lc code=end

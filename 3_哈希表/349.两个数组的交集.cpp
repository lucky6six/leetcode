/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 *
 * https://leetcode.cn/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (74.41%)
 * Likes:    898
 * Dislikes: 0
 * Total Accepted:    551.2K
 * Total Submissions: 740.1K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组 nums1 和 nums2 ，返回 它们的 交集 。输出结果中的每个元素一定是
 * 唯一 的。我们可以 不考虑输出结果的顺序 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[9,4]
 * 解释：[4,9] 也是可通过的
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 *
 *
 */
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
// @lc code=start
// key值范围大，但value只需记录有无出现————set
class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    //常见的std数据结构的构造常常可以传入其他结构的迭代器。
    set<int> nums(nums1.begin(), nums1.end());
    vector<int> ret;
    //用冒号遍历容器元素
    for (int n : nums) {
      if (find(nums2.begin(), nums2.end(), n) != nums2.end()) {
        //这里要注意是在哪边遍历又查找哪边，防止多次插入同一个值。
        ret.push_back(n);
      }
    }
    return ret;
  }
};
// @lc code=end

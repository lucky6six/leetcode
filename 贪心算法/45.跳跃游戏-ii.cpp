/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 *
 * https://leetcode.cn/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (44.76%)
 * Likes:    2761
 * Dislikes: 0
 * Total Accepted:    911.3K
 * Total Submissions: 2M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
 *
 * 每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。换句话说，如果你在 nums[i]
 * 处，你可以跳转到任意 nums[i + j] 处:
 *
 *
 * 0 <= j <= nums[i] 
 * i + j < n
 *
 *
 * 返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。
 * 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [2,3,0,1,4]
 * 输出: 2
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 1000
 * 题目保证可以到达 nums[n-1]
 *
 *
 */
// 第一反应，可以动态规划记录每个的最小跳跃次数，遍历更新，二次方复杂度
// 又想到但可以计算贪心，跳到max（目标格位置+目标格跳跃能力）
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int jump(vector<int> &nums) {
    int size = nums.size();
    int num = 0;
    int length = 0;
    int target;
    int pos = 0;
    while (pos < size - 1) {
      if (pos + nums[pos] >= size - 1) {
        num++;
        return num;
      }
      for (int i = pos + 1; i <= pos + nums[pos]; i++) {
        int tmp = i + nums[i];
        if (tmp > length) {
          length = tmp;
          target = i;
        }
      }
      pos = target;
      num++;
    }
    return num;
  }
};
// @lc code=end

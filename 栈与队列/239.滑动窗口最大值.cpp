/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode.cn/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (48.94%)
 * Likes:    2763
 * Dislikes: 0
 * Total Accepted:    589.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给你一个整数数组
 * nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的
 * k 个数字。滑动窗口每次只向右移动一位。
 *
 * 返回 滑动窗口中的最大值 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1], k = 1
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 *
 *
 */
// #include <iostream>
#include <queue>
#include <vector>

using namespace std;
//暴力平方复杂度不可取。
//我的直观感受是双指针造滑动窗口——不行！当1被删需要2变为1，此时需要原来的3变为2，迭代。即确实需要维护有序性
//开始思考有序容器
// A1 : 优先级队列
//难点在于一方面要排序，另一方面要能认知到每个元素的原始位置——即在不在窗口中
//在优先级队列中存放pair，于second放置位置
//优先级队列写法
//有时间手写一下自己的优先级队列
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> ret;
    priority_queue<pair<int, int>> queue;
    int i = 0, j = 0;
    for (i = 0; i < k; i++) {
      // push要手动构建pair
      // queue.push(nums[i],i);
      queue.push({nums[i], i});
      // emplace不用构建
      // queue.emplace(nums[i],i);
    }
    // bug: 前面遍历的过程中已经把i++过到k了，后面如果先++会跳一位。
    i--;
    while (i < n) {
      while (queue.top().second < j) {
        queue.pop();
      }
      ret.push_back(queue.top().first);
      i++;
      j++;
      if (i < n)
        queue.push({nums[i], i});
    }
    return ret;
  }
};
// @lc code=start

//显然，只要右面的某元素大于左侧，在之后的过程中，左侧不会成为窗口最大值，可以删去。

//我们可以用队列存储还没被移除的数据下标，显然其对应的值是单调递减的。

//推动窗口时，新元素进入队尾，不断弹出队尾的小值。（删去）
//推动窗口时，检查队头是否出窗口，出则删去。
//取最大值时，返回队头索引对应的值。

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> ret;
    deque<int> window;
    for (int i = 0; i < k; i++) {
      //队列中存放的只是索引，要用nums中的值比较
      while (!window.empty() && nums[i] > nums[window.back()]) {
        window.pop_back();
      }
      window.push_back(i);
    }
    int n = nums.size();
    for (int i = k; i < n; i++) {
      ret.push_back(nums[window.front()]);
      while (!window.empty() && nums[i] > nums[window.back()]) {
        window.pop_back();
      }
      window.push_back(i);
      while (window.front() <= i - k) {
        window.pop_front();
      }
    }
    ret.push_back(nums[window.front()]);
    return ret;
  }
};

// @lc code=end

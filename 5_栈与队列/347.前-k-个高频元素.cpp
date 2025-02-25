/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode.cn/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (63.64%)
 * Likes:    1812
 * Dislikes: 0
 * Total Accepted:    537.4K
 * Total Submissions: 844.4K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k
 * 高的元素。你可以按 任意顺序 返回答案。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [1], k = 1
 * 输出: [1]
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * k 的取值范围是 [1, 数组中不相同的元素的个数]
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 *
 *
 *
 *
 * 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
 *
 */
//我的常规想法：先hash表统计，再对value进行排序，
//但常规操作都是O（nlogn）的，我们需要优化。
//难以优化到O（n），还是从排序空间下手，只维护大小为k的优先级队列

//发散：若k为常量，可以直接记录k个值，做max比较，一遍遍历解决，O（nk），比较k次。
//当k为变量，不能预设，但实际类似，用优先级队列比较，比较开销小，O（nlogk）。

#include <map>
#include <queue>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
  //注意如何自定义容器比较函数
  struct Compare {
    bool operator()(const std::pair<int, int> &a,
                    const std::pair<int, int> &b) {
      return a.first > b.first;
    }
  };
  vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> m;
    for (auto n : nums) {
      m[n]++;
    }
    //优先级队列默认是大顶堆，这里需要小顶堆，每次把最小data pop出去
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
    for (auto mm : m) {
      if (q.size() == k) {
        if (mm.second > q.top().first) {
          q.pop();
          q.emplace(mm.second, mm.first);
        }
      } else {
        q.emplace(mm.second, mm.first);
      }
    }
    vector<int> ret;
    while (!q.empty()) {
      ret.push_back(q.top().second);
      q.pop();
    }
    return ret;
  }
};

// @lc code=end

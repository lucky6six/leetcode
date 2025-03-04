/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 *
 * https://leetcode.cn/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (56.12%)
 * Likes:    1089
 * Dislikes: 0
 * Total Accepted:    193.7K
 * Total Submissions: 345.1K
 * Testcase Example:
 '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n' +
  '[[],[1],[2],[],[3],[]]'
 *
 * 中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。
 *
 *
 * 例如 arr = [2,3,4] 的中位数是 3 。
 * 例如 arr = [2,3] 的中位数是 (2 + 3) / 2 = 2.5 。
 *
 *
 * 实现 MedianFinder 类:
 *
 *
 *
 * MedianFinder() 初始化 MedianFinder 对象。
 *
 *
 * void addNum(int num) 将数据流中的整数 num 添加到数据结构中。
 *
 *
 * double findMedian()
 返回到目前为止所有元素的中位数。与实际答案相差 10^-5 以内的答案将被接受。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入
 * ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
 * [[], [1], [2], [], [3], []]
 * 输出
 * [null, null, null, 1.5, null, 2.0]
 *
 * 解释
 * MedianFinder medianFinder = new MedianFinder();
 * medianFinder.addNum(1);    // arr = [1]
 * medianFinder.addNum(2);    // arr = [1, 2]
 * medianFinder.findMedian(); // 返回 1.5 ((1 + 2) / 2)
 * medianFinder.addNum(3);    // arr[1, 2, 3]
 * medianFinder.findMedian(); // return 2.0
 *
 * 提示:
 *
 *
 * -10^5 <= num <= 10^5
 * 在调用 findMedian 之前，数据结构中至少有一个元素
 * 最多 5 * 10^4 次调用 addNum 和 findMedian
 *
 *
 */
// 法1:大顶堆+小顶堆
// 法2:双指针+有序可重集合multiset
#include <queue>
using namespace std;
//  @lc code=start
class MedianFinder {
public:
  // 默认为大顶，less<int>是大顶堆，greater是小顶堆
  priority_queue<int, vector<int>, greater<int>> queMin; // 数量为quemax+1或+0
  priority_queue<int, vector<int>, less<int>> queMax;
  MedianFinder() {}

  void addNum(int num) {
    if (queMax.size() >= queMin.size()) {
      if (!queMax.empty() && queMax.top() > num) {
        int tmp = queMax.top();
        queMax.pop();
        queMax.push(num);
        queMin.push(tmp);
      } else {
        queMin.push(num);
      }
    } else {
      if (queMin.top() < num) {
        int tmp = queMin.top();
        queMin.pop();
        queMin.push(num);
        queMax.push(tmp);
      } else {
        queMax.push(num);
      }
    }
  }
  double findMedian() {
    if (queMax.size() == queMin.size())
      return (queMax.top() + queMin.top()) / (float)2;
    else
      return queMin.top();
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

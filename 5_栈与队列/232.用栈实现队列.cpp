/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 *
 * https://leetcode.cn/problems/implement-queue-using-stacks/description/
 *
 * algorithms
 * Easy (68.19%)
 * Likes:    1092
 * Dislikes: 0
 * Total Accepted:    451.4K
 * Total Submissions: 662.5K
 * Testcase Example:
 * '["MyQueue","push","push","peek","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
 *
 * 实现 MyQueue 类：
 *
 *
 * void push(int x) 将元素 x 推到队列的末尾
 * int pop() 从队列的开头移除并返回元素
 * int peek() 返回队列开头的元素
 * boolean empty() 如果队列为空，返回 true ；否则，返回 false
 *
 *
 * 说明：
 *
 *
 * 你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size,
 * 和 is empty 操作是合法的。 你所使用的语言也许不支持栈。你可以使用 list 或者
 * deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：
 * ["MyQueue", "push", "push", "peek", "pop", "empty"]
 * [[], [1], [2], [], [], []]
 * 输出：
 * [null, null, null, 1, 1, false]
 *
 * 解释：
 * MyQueue myQueue = new MyQueue();
 * myQueue.push(1); // queue is: [1]
 * myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
 * myQueue.peek(); // return 1
 * myQueue.pop(); // return 1, queue is [2]
 * myQueue.empty(); // return false
 *
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= x <= 9
 * 最多调用 100 次 push、pop、peek 和 empty
 * 假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n
 * 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。
 *
 *
 */
//两个栈颠倒，一个负责在push是按照stack的逻辑保序，另一个负责在pop和peek的时候拿
// push栈的全部数据，以颠倒栈的顺序读到。
//设置s2_enable flag,连续push/读的时候不用倒栈。
//其实不必要，判断另一个栈为空，即可说明本栈enable

#include <stack>
using namespace std;
// @lc code=start
class MyQueue {
public:
  stack<int> s1, s2;
  bool s2_enable;
  MyQueue() { s2_enable = 0; }

  void push(int x) {
    if (s2_enable) {
      while (!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
      }
      s2_enable = 0;
    }
    s1.push(x);
  }

  int pop() {
    if (!s2_enable) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
      s2_enable = 1;
    }
    int ret = s2.top();
    s2.pop();
    return ret;
  }

  int peek() {
    if (!s2_enable) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
      s2_enable = 1;
    }
    return s2.top();
  }

  bool empty() {
    if (s1.empty() && s2.empty())
      return true;
    return false;
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

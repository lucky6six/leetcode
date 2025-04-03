/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 *
 * https://leetcode.cn/problems/lru-cache/description/
 *
 * algorithms
 * Medium (54.23%)
 * Likes:    3402
 * Dislikes: 0
 * Total Accepted:    778K
 * Total Submissions: 1.4M
 * Testcase Example:
 '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
 *
 * 实现 LRUCache 类：
 *
 *
 *
 *
 * LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
 * int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1
 。
 * void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value
 ；如果不存在，则向缓存中插入该组
 * key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出
 最久未使用的关键字。
 *
 *
 * 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
 *
 *
 *
 *
 *
 * 示例：
 *
 *
 * 输入
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * 输出
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 *
 * 解释
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // 缓存是 {1=1}
 * lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
 * lRUCache.get(1);    // 返回 1
 * lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
 * lRUCache.get(2);    // 返回 -1 (未找到)
 * lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
 * lRUCache.get(1);    // 返回 -1 (未找到)
 * lRUCache.get(3);    // 返回 3
 * lRUCache.get(4);    // 返回 4
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= capacity <= 3000
 * 0 <= key <= 10000
 * 0 <= value <= 10^5
 * 最多调用 2 * 10^5 次 get 和 put
 *
 *
 */
// 可以想到hash表进行映射查找
// 为了增删改查都是O（1），需要双向链表
#include <unordered_map>
#include <vector>
using namespace std;
//  @lc code=start

class Node {
public:
  int key;
  int val;
  Node *prev;
  Node *next;
  Node() : key(0), val(0), prev(nullptr), next(nullptr) {}
  Node(int i, int j, Node *p, Node *n) : key(i), val(j), prev(p), next(n) {}
};
class LRUCache {
public:
  unordered_map<int, Node *> set;
  Node *head;
  Node *tail;
  int cap;
  int size;
  LRUCache(int capacity) {
    cap = capacity;
    size = 0;
    // 指针要先初始化再用。
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
  }

  void tohead(int key) {
    // 双边都要链接上。
    set[key]->prev->next = set[key]->next;
    set[key]->next->prev = set[key]->prev;
    set[key]->next = head->next;
    set[key]->prev = head;
    head->next->prev = set[key];
    head->next = set[key];
    return;
  }

  int get(int key) {
    if (set.find(key) != set.end()) {
      tohead(key);
      return set[key]->val;
    } else
      return -1;
  }

  void put(int key, int value) {
    if (set.find(key) != set.end()) {
      set[key]->val = value;
      tohead(key);
      return;
    }
    if (size < cap) {
      Node *tmp = new Node(key, value, head, head->next);
      head->next->prev = tmp;
      head->next = tmp;
      // 记得更新hash表
      set[key] = tmp;
      size++;
      return;
    } else {
      set.erase(tail->prev->key);
      tail->prev->prev->next = tail;
      tail->prev = tail->prev->prev;
      size--;
      put(key, value);
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

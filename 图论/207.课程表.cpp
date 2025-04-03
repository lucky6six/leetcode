/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 *
 * https://leetcode.cn/problems/course-schedule/description/
 *
 * algorithms
 * Medium (54.92%)
 * Likes:    2090
 * Dislikes: 0
 * Total Accepted:    507.3K
 * Total Submissions: 923.5K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
 *
 * 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites
 * 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须
 * 先学习课程  bi 。
 *
 *
 * 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
 *
 *
 * 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：numCourses = 2, prerequisites = [[1,0]]
 * 输出：true
 * 解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
 *
 * 示例 2：
 *
 *
 * 输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
 * 输出：false
 * 解释：总共有 2 门课程。学习课程 1
 * 之前，你需要先完成​课程 0 ；并且学习课程 0
 * 之前，你还应先完成课程 1 。这是不可能的。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * prerequisites[i] 中的所有课程对 互不相同
 *
 *
 */
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  // 记录后继节点
  vector<vector<int>> courses;
  // 记录是否遍历
  vector<int> visited;
  bool valid = true;
  void visit(int i) {
    visited[i] = 1;
    for (auto j : courses[i]) {
      // 0表示为访问过，1表示正在找环，2表示后续无环
      if (visited[j] == 0) {
        visit(j);
        if (valid == false)
          return;
      }

      else if (visited[j] == 1) {
        valid = false;
        return;
      }

      //   else if (visited[j] == 2) {
      //     continue;
      //   }
    }
    visited[i] = 2;
    return;
  }

  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    courses.resize(numCourses);
    visited.resize(numCourses);
    int sum = 0;
    for (auto i : prerequisites) {
      courses[i[1]].push_back(i[0]);
    }
    // dfs，对每个节点，遇到成环返回false，否则遍历后返回。
    for (int i = 0; i < numCourses; i++) {
      if (visited[i]) {
        continue;
      }
      visit(i);
      if (valid == false)
        return valid;
    }
    return valid;
  }
};
// @lc code=end

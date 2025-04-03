/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode.cn/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (69.36%)
 * Likes:    1903
 * Dislikes: 0
 * Total Accepted:    679.7K
 * Total Submissions: 979.9K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i
 * 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: temperatures = [73,74,75,71,69,72,76,73]
 * 输出: [1,1,4,2,1,1,0,0]
 *
 *
 * 示例 2:
 *
 *
 * 输入: temperatures = [30,40,50,60]
 * 输出: [1,1,1,0]
 *
 *
 * 示例 3:
 *
 *
 * 输入: temperatures = [30,60,90]
 * 输出: [1,1,0]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {

        int tail = temperatures.size() - 1;
        vector<int> answer(tail + 1);
        answer[tail] = 0;
        int temp, tmp;
        int day;
        tail--;
        temp = temperatures[tail];
        day = tail + 1;
        tmp = temperatures[day];
        while (tail >= 0)
        {
            if (temp < tmp)
            {
                answer[tail] = day - tail;
                if (tail == 0)
                    return answer;
                tail--;
                temp = temperatures[tail];
                day = tail + 1;
                tmp = temperatures[day];
                continue;
            }
            else
            {
                if (answer[day] == 0)
                {
                    answer[tail] = 0;
                    if (tail == 0)
                    {
                        return answer;
                    }
                    tail--;
                    temp = temperatures[tail];
                    day = tail + 1;
                    tmp = temperatures[day];
                    continue;
                }
                day = day + answer[day];
                tmp = temperatures[day];
            }
        }
        return answer;
    }
};
// @lc code=end

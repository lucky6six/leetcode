#
# @lc app=leetcode.cn id=2127 lang=python3
#
# [2127] 参加会议的最多员工数
#
import collections
# @lc code=start
class Solution:
    def maximumInvitations(self, favorite: List[int]) -> int:
        pre = collections.defaultdict(list)
        for i, j in enumerate(favorite):
            pre[j].append(i)

        seen, max_cycle_length, sequence_length = set(), 0, 0

        for node in range(len(favorite)):  # for each island, there is one and only one cycle
            # find the cycle and its length
            if node in seen: continue
            path = [node]
            while favorite[path[-1]] not in seen:
                seen.add(favorite[path[-1]])
                path.append(favorite[path[-1]])
            if favorite[path[-1]] not in path: continue
            cycle_length = len(path) - path.index(favorite[path[-1]])

            if cycle_length == 2:  # cycle can concat with other sequential nodes on the island at both left and right
                # via dfs or bfs through pre, we can find out the longest sequence left and right of the cycle
                # finally we concat the left longest sequence and the cycle itself and the right longest sequence as
                # the longest valid sequence of the island.
                max_sub_len = [0, 0]
                cycle = path[-2:]
                pre[cycle[0]].remove(cycle[1])
                pre[cycle[1]].remove(cycle[0])
                for k in [0, 1]:  # the left and right of the cycle as the start point of dfs respectively
                    dq = collections.deque([(cycle[k], 0)])
                    while dq:
                        i, depth = dq.pop()  # DFS
                        # i, depth = dq.popleft()  # BFS
                        if i in pre:
                            for j in pre[i]:
                                dq.append((j, depth + 1))
                                seen.add(j)
                        else:
                            max_sub_len[k] = max(max_sub_len[k], depth)  # get the length of longest sequence
                # 2 is the length of cycle, max_sub_len are lengths of longest sequence of both left and right ends
                sequence_length += 2 + sum(max_sub_len)
            else:  # greater than 2, the cycle can't concat with any other node
                max_cycle_length = max(max_cycle_length, cycle_length)

        # either a big cycle or some free sequences will be the final answer
        return max(max_cycle_length, sequence_length)
# @lc code=end


#
# @lc app=leetcode.cn id=209 lang=python3
#
# [209] 长度最小的子数组
#

# @lc code=start
#双指针滑动窗口
class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        sum = 0
        left = 0
        length = len(nums) + 1
        for i in range(len(nums)):
            sum += nums[i]
            while(sum >= target):
                length = length = min(length,i-left)
                sum -= nums[left]
                left += 1
        if length == len(nums) + 1:
            return 0
        return length + 1

        
            
            
# @lc code=end


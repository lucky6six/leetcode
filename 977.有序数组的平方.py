#
# @lc app=leetcode.cn id=977 lang=python3
#
# [977] 有序数组的平方
#

# @lc code=start
class Solution:
    def sortedSquares(self, nums: list[int]) -> List[int]:
        #粗暴的空间
        # return sorted(x*x for x in nums)
        # n+排序，能否在排序的过程中平方掉？
        for i in range(len(nums)):
            nums[i] = nums[i]*nums[i]
        nums.sort()
        return nums
        # 双指针法在遍历平方的同时排序    
        # res = 0 * len(nums)
        
# @lc code=end


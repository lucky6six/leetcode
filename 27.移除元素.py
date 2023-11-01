#
# @lc app=leetcode.cn id=27 lang=python3
#
# [27] 移除元素
#

# @lc code=start
class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        # while(val in nums):
        #     nums.remove(val)
        # return len(nums)
        #用迭代器结构还是会更快的
        
        #快慢指针，将其余值提前
        i = 0
        for x in nums:
            if x != val:
                nums[i] = x
                i += 1
        return i

# @lc code=end
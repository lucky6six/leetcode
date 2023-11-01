#
# @lc app=leetcode.cn id=704 lang=python3
#
# [704] 二分查找
#

# @lc code=start
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        nums.sort()
        left = 0
        right = len(nums) - 1
        #本方法考虑闭区间，right有意义
        #若考虑开区间【），15，28行要修改
        while(left <= right):
            i = (left+right)//2
            #更好的防溢出: i = left + ((right - left) / 2)
            if nums[i] == target:
                return i
            if nums[i] < target:
                #left = i 
                left = i + 1
            else:
                # right = i 
                # right 要赋值为 middle - 1，因为当前这个nums[middle]一定不是target，
                # -1一方面加快，另一方面防止卡在left与right差1或0的情况
                right = i - 1
        return -1


# @lc code=end


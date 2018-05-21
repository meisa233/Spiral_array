class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        #length=nums.__len__()
        for i in nums:
            for j in nums[nums.index(i)+1:]:
                    if i+j==target:
                        return [nums.index(i),nums[nums.index(i)+1:].index(j)+nums.index(i)+1]

if __name__ == "__main__":
    print(Solution().twoSum([3,3],6))

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        count = {}

        for i in range(len(nums)):
            elem = target - nums[i]

            if elem in count:
                return [count[elem], i]

            count[nums[i]] = i

        
        